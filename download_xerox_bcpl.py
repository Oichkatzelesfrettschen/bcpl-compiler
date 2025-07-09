#!/usr/bin/env python3

"""
Xerox Alto BCPL Source Downloader and Modernizer
Downloads BCPL source files from the Xerox repository and modernizes them for building with modern tools.
"""

import os
import sys
import requests
import re
from pathlib import Path
from urllib.parse import urljoin
import time

class XeroxBCPLDownloader:
    def __init__(self, base_dir="xerox-alto-bcpl"):
        self.base_dir = Path(base_dir)
        self.base_url = "https://raw.githubusercontent.com/kant2002/Xerox/main/Indigo/AltoSource/BCPLSOURCES.DM%211/"
        self.session = requests.Session()
        self.session.headers.update({
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36'
        })
        
        # File mapping based on the repository content
        self.files_to_download = [
            # CAE (Compiler Analysis Engine) files
            "BCAE0.bcpl", "BCAE1.bcpl", "BCAE2.bcpl", "BCAE3.bcpl", "BCAE4.bcpl", "BCAEX",
            
            # Main BCPL files
            "BCPL0.bcpl", "BCPL1.bcpl", "BCPLALTO.bcpl", "BCPLDOS.bcpl", "BCPLRDOS.bcpl",
            "BCPLIOX", "BCPLX",
            
            # Lexer files
            "BLEX0.bcpl", "BLEX0A.bcpl", "BLEX1.bcpl", "BLEX2.bcpl", "BLEXX",
            
            # Nova Code Generator files
            "BNCG0.bcpl", "BNCG1.bcpl", "BNCG2.bcpl", "BNCG3.bcpl", "BNCG4.bcpl",
            "BNCG5.bcpl", "BNCG6.bcpl", "BNCG7.bcpl", "BNCG8.bcpl", "BNCGX",
            
            # SAE (Syntax Analysis Engine) files
            "BSAE0.bcpl", "BSAE1.bcpl", "BSAE2.bcpl", "BSAE3.bcpl", "BSAE4.bcpl", "BSAEX",
            
            # Translator files
            "BTRN0.bcpl", "BTRN1.bcpl", "BTRN2.bcpl", "BTRN3.bcpl", "BTRN4.bcpl", "BTRN5.bcpl", "BTRNX",
            
            # Assembly and other files
            "BCPLD.asm", "BUTIL.asm",
            
            # Command files
            "BcplSources.cm", "DumpBcpl.cm", "LoadBcpl.cm",
            
            # Documentation
            "README.md"
        ]
    
    def download_file(self, filename):
        """Download a single file from the repository"""
        url = urljoin(self.base_url, filename)
        local_path = self.base_dir / filename
        
        print(f"📥 Downloading {filename}...")
        
        try:
            response = self.session.get(url, timeout=30)
            response.raise_for_status()
            
            # Create directories if needed
            local_path.parent.mkdir(parents=True, exist_ok=True)
            
            # Write the file
            with open(local_path, 'wb') as f:
                f.write(response.content)
            
            print(f"✅ Downloaded {filename} ({len(response.content)} bytes)")
            return True
            
        except requests.exceptions.RequestException as e:
            print(f"❌ Failed to download {filename}: {e}")
            return False
    
    def download_all_files(self):
        """Download all BCPL source files"""
        print(f"🚀 Starting download of {len(self.files_to_download)} files...")
        print(f"📁 Target directory: {self.base_dir.absolute()}")
        
        self.base_dir.mkdir(parents=True, exist_ok=True)
        
        successful_downloads = 0
        
        for filename in self.files_to_download:
            if self.download_file(filename):
                successful_downloads += 1
            
            # Be nice to the server
            time.sleep(0.5)
        
        print(f"\n🎯 Download Summary:")
        print(f"   ✅ Successful: {successful_downloads}")
        print(f"   ❌ Failed: {len(self.files_to_download) - successful_downloads}")
        print(f"   📁 Location: {self.base_dir.absolute()}")
        
        return successful_downloads == len(self.files_to_download)

class BCPLModernizer:
    def __init__(self, source_dir="xerox-alto-bcpl"):
        self.source_dir = Path(source_dir)
        self.modernized_dir = Path(source_dir) / "modernized"
    
    def modernize_bcpl_file(self, input_path, output_path):
        """Modernize a BCPL source file for compilation with modern tools"""
        print(f"🔧 Modernizing {input_path.name}...")
        
        try:
            with open(input_path, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read()
        except UnicodeDecodeError:
            # Try different encodings for old files
            try:
                with open(input_path, 'r', encoding='latin-1') as f:
                    content = f.read()
            except:
                with open(input_path, 'rb') as f:
                    content = f.read().decode('ascii', errors='ignore')
        
        # Apply modernization transformations
        modernized_content = self.apply_modernizations(content, input_path.name)
        
        # Ensure output directory exists
        output_path.parent.mkdir(parents=True, exist_ok=True)
        
        # Write modernized file
        with open(output_path, 'w', encoding='utf-8') as f:
            f.write(modernized_content)
        
        print(f"✅ Modernized {input_path.name} -> {output_path}")
        return True
    
    def apply_modernizations(self, content, filename):
        """Apply various modernization transformations to BCPL source"""
        
        # Add modern header if this is a main file
        if filename.upper().endswith('0.BCPL') or filename.upper() == 'BCPL0.BCPL':
            header = self.generate_modern_header(filename)
            content = header + content
        
        # Normalize line endings
        content = content.replace('\r\n', '\n').replace('\r', '\n')
        
        # Fix common BCPL issues for modern compilation
        content = self.fix_compiler_directives(content)
        content = self.modernize_library_includes(content)
        content = self.fix_character_constants(content)
        content = self.standardize_keywords(content)
        content = self.fix_procedure_declarations(content)
        content = self.fix_comments(content)
        content = self.add_type_annotations(content)
        
        return content
    
    def generate_modern_header(self, filename):
        """Generate a modern BCPL header with proper includes"""
        return f'''// =============================================================================
// Modernized Xerox Alto BCPL Source: {filename}
// Original: Xerox PARC Alto BCPL Compiler
// Modernized for: Modern BCPL Compiler with C23 Runtime
// Date: {time.strftime("%Y-%m-%d")}
// =============================================================================

GET "LIBHDR"
GET "BCPLX"

'''
    
    def fix_compiler_directives(self, content):
        """Fix compiler directives for modern BCPL"""
        # Handle GET directives
        content = re.sub(r'GET\s+"([^"]+)"', r'GET "\1"', content, flags=re.IGNORECASE)
        
        # Handle NEEDS directives
        content = re.sub(r'NEEDS\s+"([^"]+)"', r'GET "\1"', content, flags=re.IGNORECASE)
        
        return content
    
    def modernize_library_includes(self, content):
        """Modernize library includes for modern BCPL"""
        # Map old library names to modern equivalents
        library_mappings = {
            'ALTOHDR': 'LIBHDR',
            'STREAMS': 'IOSTREAMS',
            'DSKDEFS': 'DISKIO',
        }
        
        for old_lib, new_lib in library_mappings.items():
            content = re.sub(f'GET\\s+"{old_lib}"', f'GET "{new_lib}"', content, flags=re.IGNORECASE)
        
        return content
    
    def fix_character_constants(self, content):
        """Fix character constants for modern BCPL"""
        # Fix character constant syntax
        content = re.sub(r"'([^']*)'", r'"\\1"', content)
        
        return content
    
    def standardize_keywords(self, content):
        """Standardize BCPL keywords to modern conventions"""
        # Ensure proper case for keywords
        keywords = ['AND', 'OR', 'NOT', 'EQV', 'NEQV', 'LSHIFT', 'RSHIFT',
                   'IF', 'THEN', 'ELSE', 'TEST', 'FOR', 'TO', 'BY', 'DO',
                   'WHILE', 'UNTIL', 'REPEAT', 'REPEATWHILE', 'REPEATUNTIL',
                   'CASE', 'DEFAULT', 'ENDCASE', 'BREAK', 'LOOP', 'RETURN',
                   'RESULTIS', 'GOTO', 'UNLESS', 'SWITCHON', 'INTO',
                   'LET', 'BE', 'AND', 'VEC', 'STATIC', 'GLOBAL', 'MANIFEST',
                   'STRUCTURE', 'TABLE']
        
        for keyword in keywords:
            # Make keywords uppercase (BCPL convention)
            content = re.sub(f'\\b{keyword.lower()}\\b', keyword, content, flags=re.IGNORECASE)
        
        return content
    
    def fix_procedure_declarations(self, content):
        """Fix procedure declarations for modern BCPL"""
        # Ensure proper LET ... BE syntax
        content = re.sub(r'LET\s+(\w+)\s*\((.*?)\)\s*BE', r'LET \1(\2) BE', content, flags=re.MULTILINE)
        
        return content
    
    def fix_comments(self, content):
        """Standardize comments for modern BCPL"""
        # Convert old-style comments to modern format
        content = re.sub(r'REM\s+(.*)$', r'// \1', content, flags=re.MULTILINE)
        content = re.sub(r'//\s*\*(.*)$', r'// \1', content, flags=re.MULTILINE)
        
        return content
    
    def add_type_annotations(self, content):
        """Add type annotations where beneficial"""
        # This is a placeholder for more sophisticated type inference
        # For now, just ensure proper variable declarations
        
        return content
    
    def modernize_all_files(self):
        """Modernize all BCPL files in the source directory"""
        bcpl_files = list(self.source_dir.glob("*.bcpl"))
        header_files = list(self.source_dir.glob("*X"))  # Header files often end with X
        
        all_files = bcpl_files + header_files
        
        if not all_files:
            print("❌ No BCPL files found to modernize!")
            return False
        
        print(f"🔧 Modernizing {len(all_files)} BCPL files...")
        
        successful_modernizations = 0
        
        for source_file in all_files:
            output_file = self.modernized_dir / source_file.name
            
            if self.modernize_bcpl_file(source_file, output_file):
                successful_modernizations += 1
        
        print(f"\n🎯 Modernization Summary:")
        print(f"   ✅ Modernized: {successful_modernizations}")
        print(f"   ❌ Failed: {len(all_files) - successful_modernizations}")
        print(f"   📁 Output: {self.modernized_dir.absolute()}")
        
        return successful_modernizations == len(all_files)

def main():
    """Main function to download and modernize Xerox Alto BCPL sources"""
    print("🚀 Xerox Alto BCPL Source Downloader and Modernizer")
    print("=" * 60)
    
    # Change to the script directory
    script_dir = Path(__file__).parent
    os.chdir(script_dir)
    
    # Download sources
    downloader = XeroxBCPLDownloader()
    if not downloader.download_all_files():
        print("❌ Download failed! Cannot proceed with modernization.")
        return 1
    
    # Modernize sources
    modernizer = BCPLModernizer()
    if not modernizer.modernize_all_files():
        print("❌ Modernization failed!")
        return 1
    
    print("\n🎉 Success! Xerox Alto BCPL sources downloaded and modernized.")
    print(f"📁 Original sources: {downloader.base_dir.absolute()}")
    print(f"📁 Modernized sources: {modernizer.modernized_dir.absolute()}")
    print("\n🔧 Next steps:")
    print("   1. Review modernized sources")
    print("   2. Create CMakeLists.txt for building")
    print("   3. Build with: cmake && make")
    
    return 0

if __name__ == "__main__":
    sys.exit(main())
