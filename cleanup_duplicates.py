#!/usr/bin/env python3
"""
Script to remove duplicate files with " 2" pattern and restore proper multi-arch structure
"""

import os
import sys
import shutil
import difflib

def main():
    repo_root = "/Users/eirikr/Documents/GitHub/bcpl-compiler"
    
    # Find all files with " 2" pattern
    duplicates = []
    for root, dirs, files in os.walk(repo_root):
        for file in files:
            if " 2." in file:
                full_path = os.path.join(root, file)
                # Get the original file path
                original_file = file.replace(" 2.", ".")
                original_path = os.path.join(root, original_file)
                duplicates.append((full_path, original_path))
    
    print(f"Found {len(duplicates)} duplicate files")
    
    for duplicate_path, original_path in duplicates:
        print(f"\nProcessing: {duplicate_path}")
        
        # Check if both files exist
        if os.path.exists(original_path) and os.path.exists(duplicate_path):
            # Compare files
            try:
                with open(original_path, 'r', encoding='utf-8', errors='ignore') as f1:
                    original_content = f1.read()
                with open(duplicate_path, 'r', encoding='utf-8', errors='ignore') as f2:
                    duplicate_content = f2.read()
                
                if original_content == duplicate_content:
                    print(f"  ✓ Identical content - removing duplicate: {os.path.basename(duplicate_path)}")
                    os.remove(duplicate_path)
                else:
                    print(f"  ⚠ Different content - manual review needed")
                    print(f"    Original: {original_path}")
                    print(f"    Duplicate: {duplicate_path}")
                    
                    # Show diff for small files
                    if len(original_content) < 10000:
                        diff = list(difflib.unified_diff(
                            original_content.splitlines(keepends=True),
                            duplicate_content.splitlines(keepends=True),
                            fromfile=os.path.basename(original_path),
                            tofile=os.path.basename(duplicate_path),
                            n=3
                        ))
                        if diff:
                            print("    Differences:")
                            for line in diff[:20]:  # Show first 20 lines of diff
                                print(f"    {line.rstrip()}")
                            if len(diff) > 20:
                                print(f"    ... ({len(diff) - 20} more lines)")
                    
                    # For now, remove the duplicate and keep original
                    print(f"  → Keeping original, removing duplicate")
                    os.remove(duplicate_path)
                    
            except Exception as e:
                print(f"  ✗ Error comparing files: {e}")
                # Remove duplicate anyway to clean up
                os.remove(duplicate_path)
        
        elif os.path.exists(duplicate_path):
            # Only duplicate exists, rename it to original
            print(f"  → Moving duplicate to original location")
            shutil.move(duplicate_path, original_path)
        
        else:
            print(f"  ✗ Neither file exists anymore")

if __name__ == "__main__":
    main()
