# Repository Analysis

This document summarizes automated analysis results for the BCPL compiler repository.

All of the raw reports that underpin this summary are stored within the
repository under `docs/analysis/`. Keeping artifacts in a project-relative
directory makes the results reproducible and avoids references to machine
specific temporary locations.


## File Statistics

The following language statistics were extracted from `docs/analysis/cloc.json`:

{"header" : {
  "cloc_url"           : "github.com/AlDanial/cloc",
  "cloc_version"       : "1.98",
  "elapsed_seconds"    : 0.079768180847168,
  "n_files"            : 73,
  "n_lines"            : 19306,
  "files_per_second"   : 915.151871644967,
  "lines_per_second"   : 242026.329232572},
"C" :{
  "nFiles": 41,
  "blank": 1769,
  "comment": 3790,
  "code": 7353},
"Assembly" :{
  "nFiles": 10,
  "blank": 190,
  "comment": 191,
  "code": 1791},
"C/C++ Header" :{
  "nFiles": 17,
  "blank": 460,
  "comment": 1622,
  "code": 1405},
"CMake" :{
  "nFiles": 1,
  "blank": 47,
  "comment": 66,
  "code": 166},
"make" :{
  "nFiles": 1,
  "blank": 27,
  "comment": 12,
  "code": 122},
"Bourne Shell" :{
  "nFiles": 1,
  "blank": 4,
  "comment": 5,
  "code": 111},
"C++" :{
  "nFiles": 1,
  "blank": 7,
  "comment": 90,
  "code": 42},
"DOS Batch" :{
  "nFiles": 1,
  "blank": 9,
  "comment": 8,
  "code": 19},
"SUM": {
  "blank": 2513,
  "comment": 5784,
  "code": 11009,
  "nFiles": 73} }

The repository has a total of 5470 tracked files (excluding `.git`).

## Cyclomatic Complexity

Total nloc   Avg.NLOC  AvgCCN  Avg.token   Fun Cnt  Warning cnt   Fun Rt   nloc Rt
------------------------------------------------------------------------------------------
      7930      10.8     3.2       62.3      561            6      0.01    0.06

The complete report is available in `docs/analysis/lizard_report.txt`.

## Checksum Manifest

A SHA-256 checksum manifest of all files was generated and saved to `docs/analysis/sha256sums.txt`.

Both files are tracked in the repository for convenience. If they are missing or
out of date, regenerate them from the repository root:

```bash
mkdir -p docs/analysis
cloc --json . > docs/analysis/cloc.json
lizard -Ecpp src > docs/analysis/lizard_report.txt
sha256sum $(git ls-files) > docs/analysis/sha256sums.txt
```

Storing reports under `docs/analysis/` keeps the tree tidy and avoids absolute
paths that can become stale across machines.
## Duplicate File Cleanup

The `cleanup_duplicates.py` utility was executed to remove redundant files with a trailing `2` in their names.
A total of 292 duplicate artifacts were deleted from legacy build archives and tools directories, while five differing copies
were preserved under `archive/duplicates/` with canonical filenames. Subsequent verification confirmed no remaining files
match the duplicate pattern.
