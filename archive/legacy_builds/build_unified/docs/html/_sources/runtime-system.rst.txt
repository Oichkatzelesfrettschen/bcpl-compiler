Runtime System
==============

The BCPL runtime system provides essential services for executing BCPL programs.
It includes startup code, system call interfaces, and standard library functions.

Startup Code
------------

**Assembly Startup** (su.s, su16.s)
   Low-level program initialization:
   
   * Process initialization
   * Stack setup
   * Command-line argument processing
   * Environment variable access
   * Program entry point establishment

**System-Specific Variants**
   * ``su.s``: Standard 32/64-bit startup
   * ``su16.s``: 16-bit systems (legacy)
   * Platform-specific initialization sequences

Memory Management
-----------------

**Stack Management**
   * Frame pointer maintenance
   * Local variable allocation
   * Parameter passing conventions
   * Return address handling

**Global Data**
   * Static variable storage
   * Constant data sections
   * Global symbol resolution

System Interface
----------------

**System Call Wrappers** (sys.s, sys_*.s)
   Platform-specific system call interfaces:
   
   * ``sys_linux.s``: Linux system calls
   * ``sys_freebsd.s``: FreeBSD system calls  
   * ``sys_ia16.s``: 16-bit system interface
   
   Core system calls supported:
   
   * File I/O operations
   * Process control
   * Memory allocation
   * Time and date functions

**I/O System**
   Stream-based input/output:
   
   * Standard streams (input, output, error)
   * File operations (open, close, read, write)
   * Character and line-based I/O
   * Buffered I/O for efficiency

Standard Library
----------------

**BCPL Standard Library** (blib.bcpl)
   Core runtime functions written in BCPL:
   
   **I/O Functions**
   .. code-block:: bcpl
   
      WRCH(ch)           // Write character
      RDCH()             // Read character  
      WRITES(string)     // Write string
      WRITEF(format, ..) // Formatted output
      NEWLINE()          // Write newline
   
   **Memory Functions**
   .. code-block:: bcpl
   
      GETVEC(size)       // Allocate memory
      FREEVEC(ptr)       // Free memory
      
   **String Functions**
   .. code-block:: bcpl
   
      COMPSTRING(s1, s2) // Compare strings
      COPYSTRING(s1, s2) // Copy strings
      
   **Math Functions**
   .. code-block:: bcpl
   
      ABS(n)             // Absolute value
      MAX(a, b)          // Maximum
      MIN(a, b)          // Minimum

Global Variables
----------------

The runtime system maintains global variables:

.. code-block:: bcpl

   INPUT()        // Current input stream
   OUTPUT()       // Current output stream  
   SYSPRINT       // System error stream
   CURRENTDIR     // Current directory
   PROGRAMNAME    // Program name

Stream System
-------------

**Stream Objects**
   BCPL streams encapsulate I/O operations:
   
   * File handles
   * Buffer management
   * Error state tracking
   * End-of-file detection

**Stream Operations**
   * Opening and closing files
   * Reading and writing data
   * Seeking and positioning
   * Stream selection and switching

Error Handling
--------------

**Runtime Errors**
   The system detects and reports:
   
   * Stack overflow
   * Memory allocation failures
   * Invalid file operations
   * System call errors

**Error Reporting**
   * Error messages to SYSPRINT
   * Program termination with exit codes
   * Optional stack traces

Process Model
-------------

**Program Execution**
   * Single-threaded execution model
   * Procedure call stack
   * Return value handling
   * Program termination

**Environment Access**
   * Command-line arguments
   * Environment variables
   * Working directory
   * System resources

Debugging Support
-----------------

**Runtime Debugging**
   * Optional runtime checks
   * Memory usage tracking
   * Procedure call tracing
   * Assertion support

**Integration with Debuggers**
   * Symbol table generation
   * Debug information format
   * Breakpoint support
   * Variable inspection

Platform Portability
--------------------

**Abstraction Layer**
   The runtime provides a consistent interface across:
   
   * Different operating systems
   * Various hardware architectures
   * 16-bit, 32-bit, and 64-bit systems

**Configuration**
   * Word size adaptation (16/32/64 bit)
   * Endianness handling
   * System call mapping
   * Character encoding support

Runtime Initialization
----------------------

**Startup Sequence**
   1. Process initialization
   2. Stack setup
   3. Global variable initialization
   4. Standard stream setup
   5. Command-line processing
   6. Main program execution
   7. Cleanup and termination

**Library Initialization**
   * Standard library setup
   * System interface initialization
   * Error handling setup
   * Resource allocation
