Compiler Frontend
=================

The BCPL compiler frontend handles lexical analysis, parsing, and syntax tree construction.
It is implemented primarily in the ``src/st.bcpl`` file, which contains multiple sections
for different phases of compilation.

Lexical Analysis
----------------

The lexical analyzer (LEX sections) tokenizes BCPL source code:

**LEX1 Section**
   Core tokenization logic that recognizes:
   
   * Numbers (decimal, octal, hexadecimal)
   * Identifiers and keywords  
   * Operators and punctuation
   * String and character constants
   * Comments

**LEX2 Section**
   Symbol table management:
   
   * Hash table for identifier lookup
   * Keyword recognition
   * Symbol storage and retrieval

**LEX3 Section**
   Support functions:
   
   * Character classification
   * Number parsing utilities
   * String handling

Token Types
~~~~~~~~~~~

The compiler recognizes these token categories:

.. code-block:: c

   // Literals
   S.NUMBER        // Numeric constants
   S.STRING        // String literals  
   S.CHARCONST     // Character constants
   
   // Identifiers and keywords
   S.NAME          // User identifiers
   S.LET, S.BE     // Declaration keywords
   S.IF, S.WHILE   // Control flow keywords
   
   // Operators
   S.PLUS, S.MINUS // Arithmetic operators
   S.EQ, S.NE      // Comparison operators
   S.ASSIGN        // Assignment operator

Syntax Analysis  
---------------

The parser (SYN sections) builds an abstract syntax tree:

**SYN0 Section**
   Tree construction utilities:
   
   * Memory management for tree nodes
   * List building functions
   * Tree traversal support

**SYN1-SYN4 Sections**
   Recursive descent parser implementing BCPL grammar:
   
   * Expression parsing with operator precedence
   * Statement parsing
   * Declaration parsing
   * Block structure handling

Grammar
~~~~~~~

BCPL uses a relatively simple grammar with these main constructs:

* **Expressions**: Arithmetic, logical, and relational operations
* **Statements**: Assignments, procedure calls, control flow
* **Declarations**: Variables, procedures, and manifest constants
* **Blocks**: Compound statements with local scope

Error Handling
--------------

The frontend provides comprehensive error reporting:

* Syntax error detection and recovery
* Meaningful error messages with line numbers
* Warning generation for suspicious constructs
* Configurable error reporting levels

Symbol Table
------------

The compiler maintains symbol tables for:

* **Global symbols**: Top-level declarations
* **Local symbols**: Block-scoped identifiers  
* **Keywords**: Reserved language keywords
* **Operators**: Operator precedence and associativity

Integration
-----------

The frontend interfaces with:

* **Input system**: File handling and character input
* **Backend**: Passes syntax tree to code generation
* **Error system**: Coordinates error reporting
* **Option system**: Handles compilation flags and options
