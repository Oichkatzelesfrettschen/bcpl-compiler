#!/usr/bin/env python3
"""
OCODE to C Translator - Clean Version
Converts BCPL OCODE intermediate representation to portable C code.

This version generates cleaner C code with proper error handling and
no duplicate function definitions.
"""

import sys
from typing import Dict, List, Set

class OCODETranslator:
    """Translates OCODE intermediate representation to C code."""
    
    def __init__(self):
        self.labels: Dict[str, int] = {}
        self.label_counter = 0
        self.c_lines: List[str] = []
        self.declared_labels: Set[str] = set()
        
        # Comprehensive OCODE operation mappings based on analysis
        self.opcodes = {
            # Memory operations
            40: "LOAD_LOCAL",      # Load from local/stack
            41: "LOAD_CONSTANT",   # Load immediate constant  
            42: "LOAD_INDIRECT",   # Load through pointer
            81: "STORE_LOCAL",     # Store to local/stack
            91: "LOAD_GLOBAL",     # Load from global
            92: "STORE_GLOBAL",    # Store to global
            
            # Control flow
            43: "JUMP_UNCONDITIONAL", # Unconditional jump
            44: "JUMP_IF_ZERO",       # Jump if top of stack is zero
            45: "JUMP_IF_NOT_ZERO",   # Jump if top of stack is non-zero
            85: "CALL_FUNCTION",      # Function call
            86: "CONDITIONAL_JUMP",   # Conditional jump
            87: "BRANCH_IF_NEQ",      # Branch if not equal
            88: "BRANCH_IF_EQ",       # Branch if equal  
            89: "BRANCH_IF_LT",       # Branch if less than
            90: "JUMP",               # Jump/goto
            94: "FUNCTION_START",     # Function definition start
            95: "FUNCTION_END",       # Function definition end
            97: "RETURN",             # Return from function
            100: "LOOP_START",        # Loop start
            101: "LOOP_END",          # Loop end
            
            # Arithmetic operations
            8: "ADD",                 # Addition
            9: "SUBTRACT",            # Subtraction
            10: "MULTIPLY",           # Multiplication
            11: "DIVIDE",             # Division
            12: "MODULO",             # Modulo operation
            14: "COMPARE",            # Comparison
            15: "NEGATE",             # Negation
            20: "LESS_THAN",          # Less than comparison
            
            # Stack operations
            51: "DUPLICATE",          # Duplicate top of stack
            68: "POP",               # Pop from stack
            79: "PUSH_STRING",       # Push string constant
            
            # I/O operations
            3: "WRITE_CHAR",         # Write character
            4: "WRITE_STRING",       # Write string
            5: "READ_CHAR",          # Read character
            6: "READ_LINE",          # Read line
            
            # Special operations
            49: "FUNCTION_HEADER",   # Function header
            69: "LOCAL_VAR",         # Local variable allocation
            70: "TEMP_VAR",          # Temporary variable
            76: "STRING_CONSTANT",   # String constant definition
            103: "END_BLOCK",        # End of block
        }
        
    def translate_ocode_file(self, ocode_file: str, c_file: str) -> None:
        """Translate an OCODE file to C."""
        
        with open(ocode_file, 'r') as f:
            ocode_text = f.read()
            
        c_code = self.translate_ocode(ocode_text)
        
        with open(c_file, 'w') as f:
            f.write(c_code)
            
    def translate_ocode(self, ocode_text: str) -> str:
        """Translate OCODE text to C code."""
        
        # Parse OCODE tokens
        tokens = ocode_text.split()
        
        # Pre-scan for all labels to generate forward declarations
        self.prescan_labels(tokens)
        
        # Generate complete C code
        c_code = self.generate_c_header()
        
        # Start main BCPL function
        self.c_lines.append("static void bcpl_start(void) {")
        self.c_lines.append("    // Generated from OCODE")
        self.c_lines.append("    bcpl_word_t A = 0, B = 0, C = 0; // BCPL registers")
        self.c_lines.append("")
        
        # Process OCODE tokens
        i = 0
        while i < len(tokens):
            token = tokens[i]
            
            if token.startswith('L'):
                # Label
                label = token
                if label not in self.labels:
                    self.labels[label] = self.label_counter
                    self.label_counter += 1
                self.c_lines.append(f"    {label}:")
                
            elif token.isdigit() or (token.startswith('-') and token[1:].isdigit()):
                opcode = int(token)
                i = self.process_opcode(tokens, i, opcode)
                continue
                
            i += 1
        
        self.c_lines.append("}")
        self.c_lines.append("")
        self.c_lines.append("int main(int argc, char* argv[]) {")
        self.c_lines.append("    bcpl_init(argc, argv);")
        self.c_lines.append("    bcpl_start();")
        self.c_lines.append("    return 0;")
        self.c_lines.append("}")
        
        # Combine all parts
        for line in self.c_lines:
            c_code += line + "\n"
            
        return c_code
    
    def prescan_labels(self, tokens: List[str]) -> None:
        """Pre-scan tokens to find all labels."""
        i = 0
        while i < len(tokens):
            token = tokens[i]
            if token.startswith('L') and token[1:].isdigit():
                self.declared_labels.add(token)
                i += 1
            elif token.isdigit():
                opcode = int(token)
                # Check if this opcode has a target operand that might be a label
                if opcode in [43, 85, 86, 87, 88, 89, 90] and i + 1 < len(tokens):
                    target = tokens[i + 1]
                    if target.isdigit():
                        # Numeric target, generate a label for it
                        self.declared_labels.add(f"L{target}")
                        i += 2
                    elif target.startswith('L'):
                        self.declared_labels.add(target)
                        i += 2
                    else:
                        i += 1
                elif opcode in [40, 41, 42, 81, 91, 94, 95, 100, 101] and i + 1 < len(tokens):
                    # These opcodes have operands, skip the operand
                    i += 2
                else:
                    i += 1
            else:
                i += 1
        
    def process_opcode(self, tokens: List[str], index: int, opcode: int) -> int:
        """Process an OCODE opcode and return next index."""
        
        op_name = self.opcodes.get(opcode, f"UNKNOWN_{opcode}")
        
        # Memory operations
        if opcode == 40:  # LOAD_LOCAL
            if index + 1 < len(tokens):
                addr = tokens[index + 1]
                self.c_lines.append(f"    bcpl_push(bcpl_locals[{addr}]); // LOAD_LOCAL")
                return index + 2
                
        elif opcode == 41:  # LOAD_CONSTANT
            if index + 1 < len(tokens):
                value = tokens[index + 1]
                self.c_lines.append(f"    bcpl_push({value}); // LOAD_CONSTANT")
                return index + 2
                
        elif opcode == 42:  # LOAD_INDIRECT
            if index + 1 < len(tokens):
                addr = tokens[index + 1]
                self.c_lines.append(f"    bcpl_push(bcpl_load_indirect({addr})); // LOAD_INDIRECT")
                return index + 2
                
        elif opcode == 81:  # STORE_LOCAL
            if index + 1 < len(tokens):
                addr = tokens[index + 1]
                self.c_lines.append(f"    bcpl_locals[{addr}] = bcpl_pop(); // STORE_LOCAL")
                return index + 2
                
        elif opcode == 91:  # LOAD_GLOBAL
            if index + 1 < len(tokens):
                addr = tokens[index + 1]
                self.c_lines.append(f"    bcpl_push(bcpl_globals[{addr}]); // LOAD_GLOBAL")
                return index + 2
                
        elif opcode == 92:  # STORE_GLOBAL
            self.c_lines.append(f"    {{ bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; }} // STORE_GLOBAL")
            return index + 1
            
        # Control flow operations
        elif opcode == 43:  # JUMP_UNCONDITIONAL
            if index + 1 < len(tokens):
                target = tokens[index + 1]
                if target.startswith('L'):
                    self.c_lines.append(f"    goto {target}; // JUMP")
                else:
                    self.c_lines.append(f"    goto L{target}; // JUMP")
                return index + 2
                
        elif opcode == 85:  # CALL_FUNCTION
            if index + 1 < len(tokens):
                target = tokens[index + 1]
                if target.startswith('L'):
                    self.c_lines.append(f"    goto {target}; // CALL_FUNCTION (as GOTO)")
                else:
                    self.c_lines.append(f"    goto L{target}; // CALL_FUNCTION (as GOTO)")
                return index + 2
                
        elif opcode == 86:  # CONDITIONAL_JUMP
            if index + 1 < len(tokens):
                target = tokens[index + 1]
                if target.startswith('L'):
                    self.c_lines.append(f"    if (bcpl_pop()) goto {target}; // CONDITIONAL_JUMP")
                else:
                    self.c_lines.append(f"    if (bcpl_pop()) goto L{target}; // CONDITIONAL_JUMP")
                return index + 2
                
        elif opcode == 87:  # BRANCH_IF_NEQ
            if index + 1 < len(tokens):
                target = tokens[index + 1]
                if target.startswith('L'):
                    self.c_lines.append(f"    {{ bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto {target}; }} // BRANCH_IF_NEQ")
                else:
                    self.c_lines.append(f"    {{ bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L{target}; }} // BRANCH_IF_NEQ")
                return index + 2
                
        elif opcode == 88:  # BRANCH_IF_EQ
            if index + 1 < len(tokens):
                target = tokens[index + 1]
                if target.startswith('L'):
                    self.c_lines.append(f"    {{ bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto {target}; }} // BRANCH_IF_EQ")
                else:
                    self.c_lines.append(f"    {{ bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L{target}; }} // BRANCH_IF_EQ")
                return index + 2
                
        elif opcode == 89:  # BRANCH_IF_LT
            if index + 1 < len(tokens):
                target = tokens[index + 1]
                if target.startswith('L'):
                    self.c_lines.append(f"    {{ bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto {target}; }} // BRANCH_IF_LT")
                else:
                    self.c_lines.append(f"    {{ bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L{target}; }} // BRANCH_IF_LT")
                return index + 2
                
        elif opcode == 90:  # JUMP/GOTO
            if index + 1 < len(tokens):
                target = tokens[index + 1]
                if target.startswith('L'):
                    self.c_lines.append(f"    goto {target}; // GOTO")
                else:
                    self.c_lines.append(f"    goto L{target}; // GOTO")
                return index + 2
                
        elif opcode == 94:  # FUNCTION_START
            if index + 1 < len(tokens):
                func_info = tokens[index + 1]
                self.c_lines.append(f"    // FUNCTION_START {func_info}")
                return index + 2
                
        elif opcode == 95:  # FUNCTION_END  
            if index + 1 < len(tokens):
                func_info = tokens[index + 1]
                self.c_lines.append(f"    // FUNCTION_END {func_info}")
                return index + 2
                
        elif opcode == 97:  # RETURN
            self.c_lines.append(f"    return; // RETURN")
            return index + 1
            
        elif opcode == 100:  # LOOP_START
            if index + 1 < len(tokens):
                label = tokens[index + 1]
                self.c_lines.append(f"    // LOOP_START {label}")
                return index + 2
                
        elif opcode == 101:  # LOOP_END
            if index + 1 < len(tokens):
                label = tokens[index + 1]
                self.c_lines.append(f"    // LOOP_END {label}")
                return index + 2
        
        # Arithmetic operations
        elif opcode == 8:  # ADD
            self.c_lines.append(f"    {{ bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); }} // ADD")
            return index + 1
            
        elif opcode == 9:  # SUBTRACT
            self.c_lines.append(f"    {{ bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); }} // SUBTRACT")
            return index + 1
            
        elif opcode == 10:  # MULTIPLY  
            self.c_lines.append(f"    {{ bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); }} // MULTIPLY")
            return index + 1
            
        elif opcode == 11:  # DIVIDE
            self.c_lines.append(f"    {{ bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); }} // DIVIDE")
            return index + 1
            
        elif opcode == 12:  # MODULO
            self.c_lines.append(f"    {{ bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a % b : 0); }} // MODULO")
            return index + 1
            
        elif opcode == 14:  # COMPARE
            self.c_lines.append(f"    {{ bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); }} // COMPARE")
            return index + 1
            
        elif opcode == 15:  # NEGATE
            self.c_lines.append(f"    bcpl_push(-bcpl_pop()); // NEGATE")
            return index + 1
            
        elif opcode == 20:  # LESS_THAN
            self.c_lines.append(f"    {{ bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); }} // LESS_THAN")
            return index + 1
        
        # Stack operations  
        elif opcode == 51:  # DUPLICATE
            if index + 1 < len(tokens):
                depth = tokens[index + 1] 
                self.c_lines.append(f"    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - {depth}]); // DUPLICATE")
                return index + 2
            else:
                self.c_lines.append(f"    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1]); // DUPLICATE_TOP")
                return index + 1
                
        elif opcode == 68:  # POP
            self.c_lines.append(f"    bcpl_pop(); // POP")
            return index + 1
            
        elif opcode == 79:  # PUSH_STRING
            self.c_lines.append(f"    // PUSH_STRING - string handling")
            return index + 1
        
        # I/O operations
        elif opcode == 3:  # WRITE_CHAR
            self.c_lines.append(f"    bcpl_wrch(bcpl_pop()); // WRITE_CHAR")
            return index + 1
            
        elif opcode == 4:  # WRITE_STRING
            self.c_lines.append(f"    bcpl_writes(bcpl_pop()); // WRITE_STRING")
            return index + 1
            
        elif opcode == 5:  # READ_CHAR
            self.c_lines.append(f"    bcpl_push(bcpl_rdch()); // READ_CHAR")
            return index + 1
            
        elif opcode == 6:  # READ_LINE
            self.c_lines.append(f"    bcpl_push(bcpl_rdline()); // READ_LINE")
            return index + 1
        
        # Special operations
        elif opcode == 49:  # FUNCTION_HEADER
            # Handle function header with parameter count
            if index + 1 < len(tokens):
                param_count = tokens[index + 1]
                self.c_lines.append(f"    // FUNCTION_HEADER - {param_count} parameters")
                return index + 2
            return index + 1
            
        elif opcode == 69:  # LOCAL_VAR
            self.c_lines.append(f"    // LOCAL_VAR allocation")
            return index + 1
            
        elif opcode == 70:  # TEMP_VAR
            self.c_lines.append(f"    // TEMP_VAR allocation")
            return index + 1
            
        elif opcode == 76:  # STRING_CONSTANT
            self.c_lines.append(f"    // STRING_CONSTANT definition")
            return index + 1
            
        elif opcode == 103:  # END_BLOCK
            self.c_lines.append(f"    // END_BLOCK")
            return index + 1
            
        else:
            # Unknown or unimplemented opcode
            self.c_lines.append(f"    // {op_name} {opcode} - not implemented")
            
        return index + 1
        
    def generate_c_header(self) -> str:
        """Generate C header and includes."""
        return '''/**
 * Generated C code from BCPL OCODE
 * Platform-agnostic BCPL runtime
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// BCPL runtime types
typedef int32_t bcpl_word_t;
typedef bcpl_word_t* bcpl_vector_t;

// Global BCPL context
static bcpl_word_t bcpl_globals[10000];
static bcpl_word_t bcpl_locals[1000];
static bcpl_word_t bcpl_stack[10000];
static int bcpl_stack_ptr = 0;
static int bcpl_argc = 0;
static char** bcpl_argv = NULL;

// BCPL runtime functions
static void bcpl_push(bcpl_word_t value) {
    if (bcpl_stack_ptr >= 10000) {
        fprintf(stderr, "BCPL stack overflow\\n");
        exit(1);
    }
    bcpl_stack[bcpl_stack_ptr++] = value;
}

static bcpl_word_t bcpl_pop(void) {
    if (bcpl_stack_ptr <= 0) {
        fprintf(stderr, "BCPL stack underflow\\n");
        exit(1);
    }
    return bcpl_stack[--bcpl_stack_ptr];
}

static void bcpl_store_global(int index, bcpl_word_t value) {
    if (index >= 0 && index < 10000) {
        bcpl_globals[index] = value;
    }
}

static bcpl_word_t bcpl_load_global(int index) {
    if (index >= 0 && index < 10000) {
        return bcpl_globals[index];
    }
    return 0;
}

static bcpl_word_t bcpl_load_indirect(bcpl_word_t addr) {
    // Simplified indirect load - in real BCPL this would access memory
    if (addr >= 0 && addr < 10000) {
        return bcpl_globals[addr];
    }
    return 0;
}

// BCPL I/O functions
static void bcpl_wrch(bcpl_word_t ch) {
    putchar(ch);
    fflush(stdout);
}

static bcpl_word_t bcpl_rdch(void) {
    return getchar();
}

static bcpl_word_t bcpl_rdline(void) {
    // Simplified readline - return address of input buffer
    static char buffer[256];
    if (fgets(buffer, sizeof(buffer), stdin)) {
        return (bcpl_word_t)(uintptr_t)buffer;
    }
    return 0;
}

// BCPL string functions
static void bcpl_writes(bcpl_word_t str_addr) {
    // In BCPL, strings are typically stored as length-prefixed
    // For simplicity, we'll treat this as a C string pointer
    char* str = (char*)(uintptr_t)str_addr;
    if (str) {
        printf("%s", str);
        fflush(stdout);
    }
}

// BCPL memory management
static bcpl_word_t bcpl_getvec(bcpl_word_t size) {
    // Allocate vector/array
    bcpl_word_t* vec = (bcpl_word_t*)malloc(size * sizeof(bcpl_word_t));
    if (vec) {
        memset(vec, 0, size * sizeof(bcpl_word_t));
        return (bcpl_word_t)(uintptr_t)vec;
    }
    return 0;
}

static void bcpl_freevec(bcpl_word_t vec_addr) {
    // Free vector/array
    void* vec = (void*)(uintptr_t)vec_addr;
    if (vec) {
        free(vec);
    }
}

static void bcpl_init(int argc, char* argv[]) {
    bcpl_argc = argc;
    bcpl_argv = argv;
    
    // Initialize BCPL runtime
    memset(bcpl_globals, 0, sizeof(bcpl_globals));
    memset(bcpl_locals, 0, sizeof(bcpl_locals));
    memset(bcpl_stack, 0, sizeof(bcpl_stack));
    bcpl_stack_ptr = 0;
}

// Main BCPL program entry point - forward declaration
static void bcpl_start(void);

'''

def main():
    if len(sys.argv) != 3:
        print("Usage: ocode_to_c_clean.py input.O output.c", file=sys.stderr)
        sys.exit(1)
        
    ocode_file = sys.argv[1]
    c_file = sys.argv[2]
    
    try:
        translator = OCODETranslator()
        translator.translate_ocode_file(ocode_file, c_file)
        print(f"Translated {ocode_file} -> {c_file}")
        
    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()
