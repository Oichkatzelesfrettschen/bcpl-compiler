#!/usr/bin/env python3
"""Detect and clean duplicate files ending with the ``" 2.*"`` pattern.

Usage
-----
```
python cleanup_duplicates.py [--repo-root PATH]
```

``--repo-root`` sets the root directory to scan.  When omitted, the directory
containing this script is used.  For each file matching ``* 2.*`` the script
checks whether the original file (with the ``" 2"`` portion removed) exists.  If
both files exist and are identical, the duplicate is removed.  If the contents
diverge or the original is missing, the duplicate is moved to
``archive/duplicates/`` preserving its relative directory structure.

Directories inside ``archive/duplicates`` are ignored while scanning to avoid
infinite recursion.
"""
from __future__ import annotations

import argparse
import filecmp
import os
import shutil
from pathlib import Path


def parse_args() -> argparse.Namespace:
    """Parse command-line arguments."""
    parser = argparse.ArgumentParser(description="Remove duplicate files")
    parser.add_argument(
        "--repo-root",
        type=Path,
        default=Path(__file__).resolve().parent,
        help="Root directory to scan (defaults to script location)",
    )
    return parser.parse_args()



def is_within_archive(path: Path, archive_root: Path) -> bool:
    """Return ``True`` if *path* is inside the duplicates archive."""
    try:
        path.resolve().relative_to(archive_root.resolve())
        return True
    except ValueError:
        return False


def find_duplicates(repo_root: Path, archive_root: Path) -> list[tuple[Path, Path]]:
    """Return a list of ``(duplicate, original)`` file pairs."""
    pairs: list[tuple[Path, Path]] = []
    archive_duplicates = archive_root
    for dirpath, dirnames, filenames in os.walk(repo_root):
        current = Path(dirpath)
        if current.resolve() == archive_duplicates.resolve():
            dirnames.clear()
            continue
        if is_within_archive(current, archive_root):
            continue
        for name in filenames:
            if " 2." not in name:
                continue
            duplicate = current / name
            if is_within_archive(duplicate, archive_root):
                continue
            original = current / name.replace(" 2.", ".", 1)
            pairs.append((duplicate, original))
    return pairs


def move_to_archive(path: Path, repo_root: Path, archive_root: Path) -> None:
    """Move *path* into the archive directory preserving its relative path."""
    target = archive_root / path.relative_to(repo_root)
    target.parent.mkdir(parents=True, exist_ok=True)
    shutil.move(str(path), target)


def handle_pair(duplicate: Path, original: Path, repo_root: Path, archive_root: Path) -> None:
    """Process a single duplicate/original pair."""
    if original.exists() and duplicate.exists():
        if filecmp.cmp(duplicate, original, shallow=False):
            print(f"✓ Removing identical duplicate {duplicate}")
            duplicate.unlink()
        else:
            print(f"⚠ Moving differing duplicate {duplicate}")
            move_to_archive(duplicate, repo_root, archive_root)
    elif duplicate.exists():
        print(f"→ Original missing; archiving {duplicate}")
        move_to_archive(duplicate, repo_root, archive_root)
    else:
        print(f"✗ {duplicate} no longer exists")


def main() -> None:
    args = parse_args()

    repo_root = args.repo_root.resolve()
    if not repo_root.is_dir():
        raise SystemExit(f"Repository root '{repo_root}' does not exist or is not a directory")

    archive_root = repo_root / "archive" / "duplicates"

    pairs = find_duplicates(repo_root, archive_root)
    print(f"Found {len(pairs)} duplicate files")
    for dup, orig in pairs:
        handle_pair(dup, orig, repo_root, archive_root)


if __name__ == "__main__":
    main()
