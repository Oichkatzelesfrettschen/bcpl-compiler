#!/usr/bin/env python3
"""Detect and clean duplicate files ending with the ' 2.*' pattern.

For each file matching ``* 2.*`` this script checks whether the original
file (with the ``" 2"`` portion removed) exists.  If both files exist and are
identical, the duplicate is removed.  If the contents differ or the original
is missing, the duplicate is moved to ``archive/duplicates/`` preserving the
relative directory structure.  Directories inside ``archive/duplicates`` are
ignored while scanning to avoid infinite recursion.
"""
from __future__ import annotations

import filecmp
import shutil
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent
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
    for p in REPO_ROOT.rglob("* 2.*"):
        if is_within_archive(p):
            continue
        original = Path(str(p).replace(" 2.", ".", 1))
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
    pairs = find_duplicates()
    print(f"Found {len(pairs)} duplicate files")
    for dup, orig in pairs:
        handle_pair(dup, orig)


if __name__ == "__main__":
    main()
