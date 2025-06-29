#!/usr/bin/env python3
"""
Convert GNU Assembler (GAS) syntax to Clang/LLVM compatible assembly for macOS
"""

import sys
import re

def convert_gas_to_clang(gas_content):
    """Convert GAS syntax to Clang-compatible syntax"""
    lines = gas_content.split('\n')
    converted_lines = []
    
    for line in lines:
        # Skip empty lines and preserve them
        if not line.strip():
            converted_lines.append(line)
            continue
            
        # Remove leading/trailing whitespace but preserve indentation
        stripped = line.strip()
        indent = line[:len(line) - len(line.lstrip())]
        
        # Convert .globl to .global
        stripped = re.sub(r'\.globl\b', '.global', stripped)
        
        # Convert .equ to .set on macOS
        stripped = re.sub(r'\.equ\b', '.set', stripped)
        
        # Handle section directives - simplify for macOS
        stripped = re.sub(r'\.section\s+\.text', '.text', stripped)
        stripped = re.sub(r'\.section\s+\.data', '.data', stripped)
        
        # Remove .type and .size directives (not supported on macOS)
        if re.match(r'\s*\.type\b', stripped) or re.match(r'\s*\.size\b', stripped):
            continue
            
        # Handle GNU-specific directives that might cause issues
        if re.match(r'\s*\.ident\b', stripped):
            continue
            
        # Add back indentation
        converted_lines.append(indent + stripped)
    
    return '\n'.join(converted_lines)

def main():
    if len(sys.argv) != 3:
        print("Usage: gas_to_clang.py input.s output.s", file=sys.stderr)
        sys.exit(1)
        
    input_file = sys.argv[1]
    output_file = sys.argv[2]
    
    try:
        with open(input_file, 'r') as f:
            gas_content = f.read()
            
        clang_content = convert_gas_to_clang(gas_content)
        
        with open(output_file, 'w') as f:
            f.write(clang_content)
            
        print(f"Converted {input_file} -> {output_file}")
        
    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()
