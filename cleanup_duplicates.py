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

import filecmp
import shutil
import argparse
import os
from pathlib import Path
import argparse


def parse_args() -> argparse.Namespace:
    """Parse command-line arguments."""
    parser = argparse.ArgumentParser(description="Remove duplicate files")
    parser.add_argument(
        "--repo-root",
        type=Path,
        default=Path(__file__).resolve().parents[0],
        help="Root directory to scan (defaults to script location)",
    )
    return parser.parse_args()


REPO_ROOT: Path
ARCHIVE_ROOT: Path
parser = argparse.ArgumentParser(description="Clean up '* 2.*' duplicates")
parser.add_argument(
    "root",
    nargs="?",
    default=Path(__file__).resolve().parent,
    type=Path,
    help="Repository root containing files to scan",
)
args = parser.parse_args()

REPO_ROOT = args.root.resolve()
ARCHIVE_ROOT = REPO_ROOT / "archive" / "duplicates"


def is_within_archive(path: Path) -> bool:
    """Return True if *path* is inside the duplicates archive."""
    try:
        path.relative_to(ARCHIVE_ROOT)
        return True
    except ValueError:
        return False


def find_duplicates() -> list[tuple[Path, Path]]:
    """Return a list of (duplicate, original) file pairs."""
    pairs: list[tuple[Path, Path]] = []
    for dirpath, dirnames, filenames in os.walk(REPO_ROOT):
        current = Path(dirpath)
        if is_within_archive(current):
            dirnames.clear()
            continue
        for name in filenames:
            if " 2." not in name:
                continue
            p = current / name
            if is_within_archive(p):
                continue
            original = current / name.replace(" 2.", ".", 1)
            pairs.append((p, original))
        original = p.with_name(p.name.replace(" 2.", ".", 1))
        pairs.append((p, original))
    return pairs


def move_to_archive(path: Path) -> None:
    """Move *path* into the archive directory preserving its relative path."""
    target = ARCHIVE_ROOT / path.relative_to(REPO_ROOT)
    target.parent.mkdir(parents=True, exist_ok=True)
    shutil.move(str(path), target)


def handle_pair(duplicate: Path, original: Path) -> None:
    """Process a single duplicate/original pair."""
    if original.exists() and duplicate.exists():
        if filecmp.cmp(duplicate, original, shallow=False):
            print(f"✓ Removing identical duplicate {duplicate}")
            duplicate.unlink()
        else:
            print(f"⚠ Moving differing duplicate {duplicate}")
            move_to_archive(duplicate)
    elif duplicate.exists():
        print(f"→ Original missing; archiving {duplicate}")
        move_to_archive(duplicate)
    else:
        print(f"✗ {duplicate} no longer exists")


def main() -> None:
    args = parse_args()

    global REPO_ROOT, ARCHIVE_ROOT
    REPO_ROOT = args.repo_root.resolve()
    ARCHIVE_ROOT = REPO_ROOT / "archive" / "duplicates"

    pairs = find_duplicates()
    print(f"Found {len(pairs)} duplicate files")
    for dup, orig in pairs:
        handle_pair(dup, orig)


if __name__ == "__main__":
    main()
