Examples
========

This section provides practical examples of BCPL programming and compiler usage.

Hello World
-----------

The classic first program:

.. code-block:: bcpl

   GET "LIBHDR"
   
   LET START() BE
   $(
      WRITES("Hello, World!*N")
   $)

Compile and run:

.. code-block:: bash

   bcpl hello.bcpl
   ./hello

Basic I/O
---------

Reading and writing data:

.. code-block:: bcpl

   GET "LIBHDR"
   
   LET START() BE
   $(
      LET name = VEC 50
      
      WRITES("Enter your name: ")
      READNAME(name)
      WRITEF("Hello, %S!*N", name)
   $)
   
   AND READNAME(v) BE
   $(
      LET ch = 0
      LET i = 1
      
      $( ch := RDCH()
         IF ch = '*N' | ch = ENDSTREAMCH BREAK
         v!i := ch
         i := i + 1
      $) REPEAT
      
      v!0 := i - 1  // Set string length
   $)

Factorial Calculation
---------------------

Recursive and iterative implementations:

.. code-block:: bcpl

   GET "LIBHDR"
   
   LET START() BE
   $(
      FOR i = 1 TO 10 DO
         WRITEF("Factorial of %N = %N*N", i, FACTORIAL(i))
   $)
   
   AND FACTORIAL(n) = n <= 1 -> 1, n * FACTORIAL(n - 1)
   
   AND ITERATIVE_FACTORIAL(n) = VALOF
   $(
      LET result = 1
      FOR i = 2 TO n DO result := result * i
      RESULTIS result
   $)

Data Structures
---------------

Working with vectors and structures:

.. code-block:: bcpl

   GET "LIBHDR"
   
   // Simple linked list implementation
   MANIFEST $(
      LIST_VALUE = 0
      LIST_NEXT  = 1
      LIST_SIZE  = 2
   $)
   
   LET START() BE
   $(
      LET list = 0
      
      // Add some numbers
      FOR i = 1 TO 5 DO
         list := ADD_TO_LIST(list, i * 10)
      
      // Print the list
      PRINT_LIST(list)
      
      // Clean up
      FREE_LIST(list)
   $)
   
   AND ADD_TO_LIST(list, value) = VALOF
   $(
      LET new_node = GETVEC(LIST_SIZE)
      new_node!LIST_VALUE := value
      new_node!LIST_NEXT := list
      RESULTIS new_node
   $)
   
   AND PRINT_LIST(list) BE
   $(
      WRITES("List contents: ")
      WHILE list ~= 0 DO
      $(
         WRITEF("%N ", list!LIST_VALUE)
         list := list!LIST_NEXT
      $)
      NEWLINE()
   $)
   
   AND FREE_LIST(list) BE
   $(
      WHILE list ~= 0 DO
      $(
         LET next = list!LIST_NEXT
         FREEVEC(list)
         list := next
      $)
   $)

File Processing
---------------

Reading and processing files:

.. code-block:: bcpl

   GET "LIBHDR"
   
   LET START() BE
   $(
      LET input = FINDINPUT("input.txt")
      LET output = FINDOUTPUT("output.txt")
      
      IF input = 0 DO
      $(
         WRITES("Cannot open input file*N")
         RETURN
      $)
      
      IF output = 0 DO
      $(
         WRITES("Cannot create output file*N")
         ENDREAD()
         RETURN
      $)
      
      SELECTINPUT(input)
      SELECTOUTPUT(output)
      
      COPY_UPPERCASE()
      
      ENDREAD()
      ENDWRITE()
   $)
   
   AND COPY_UPPERCASE() BE
   $(
      LET ch = 0
      
      $( ch := RDCH()
         IF ch = ENDSTREAMCH BREAK
         
         // Convert to uppercase
         IF 'a' <= ch <= 'z' DO
            ch := ch - 'a' + 'A'
            
         WRCH(ch)
      $) REPEAT
   $)

String Processing
-----------------

String manipulation and parsing:

.. code-block:: bcpl

   GET "LIBHDR"
   
   LET START() BE
   $(
      LET text = "The quick brown fox jumps"
      LET word_count = COUNT_WORDS(text)
      
      WRITEF("Text: '%S'*N", text)
      WRITEF("Word count: %N*N", word_count)
      
      REVERSE_WORDS(text)
      WRITEF("Reversed: '%S'*N", text)
   $)
   
   AND COUNT_WORDS(s) = VALOF
   $(
      LET count = 0
      LET in_word = FALSE
      
      FOR i = 1 TO s%0 DO
      $(
         LET ch = s%i
         IF ch = ' ' | ch = '*T' THEN
            in_word := FALSE
         ELSE IF ~in_word THEN
         $(
            in_word := TRUE
            count := count + 1
         $)
      $)
      
      RESULTIS count
   $)
   
   AND REVERSE_WORDS(s) BE
   $(
      // Simple word reversal implementation
      LET len = s%0
      FOR i = 1 TO len/2 DO
      $(
         LET temp = s%i
         s%i := s%(len + 1 - i)
         s%(len + 1 - i) := temp
      $)
   $)

Command Line Processing
-----------------------

Handling command line arguments:

.. code-block:: bcpl

   GET "LIBHDR"
   
   LET START() BE
   $(
      LET argv = VEC 50
      LET argc = RDARGS("INPUT/A,OUTPUT,VERBOSE/S", argv, 50)
      
      IF argc = 0 DO
      $(
         WRITES("Usage: program INPUT/A [OUTPUT] [VERBOSE/S]*N")
         RETURN
      $)
      
      LET input_file = argv!0
      LET output_file = argv!1
      LET verbose = argv!2
      
      IF verbose DO
         WRITEF("Processing file: %S*N", input_file)
      
      PROCESS_FILE(input_file, output_file)
   $)
   
   AND PROCESS_FILE(input_name, output_name) BE
   $(
      // File processing implementation
      WRITEF("Would process %S", input_name)
      IF output_name DO
         WRITEF(" to %S", output_name)
      NEWLINE()
   $)

Advanced Features
-----------------

Using BCPL's advanced features:

.. code-block:: bcpl

   GET "LIBHDR"
   
   // Coroutine example
   LET START() BE
   $(
      LET producer = CREATECO(PRODUCER, 200)
      LET consumer = CREATECO(CONSUMER, 200)
      
      // Set up communication
      COWAIT(producer)
   $)
   
   AND PRODUCER() BE
   $(
      FOR i = 1 TO 10 DO
      $(
         WRITEF("Producing: %N*N", i)
         COWAIT()  // Yield to consumer
      $)
   $)
   
   AND CONSUMER() BE
   $(
      FOR i = 1 TO 10 DO
      $(
         COWAIT()  // Wait for producer
         WRITEF("Consuming item %N*N", i)
      $)
   $)

Debugging Examples
------------------

Using debugging features:

.. code-block:: bcpl

   GET "LIBHDR"
   
   MANIFEST $(
      DEBUG = TRUE
   $)
   
   LET START() BE
   $(
      DEBUG_PRINT("Starting program")
      
      LET result = RISKY_FUNCTION(42)
      
      WRITEF("Result: %N*N", result)
   $)
   
   AND DEBUG_PRINT(msg) BE
   $(
      IF DEBUG DO
         WRITEF("[DEBUG] %S*N", msg)
   $)
   
   AND RISKY_FUNCTION(n) = VALOF
   $(
      DEBUG_PRINT("Entering risky function")
      
      IF n < 0 DO
      $(
         WRITES("Error: negative input*N")
         RESULTIS -1
      $)
      
      LET result = n * n + 1
      DEBUG_PRINT("Computed result")
      
      RESULTIS result
   $)

Compilation Examples
--------------------

Different compilation modes:

.. code-block:: bash

   # Basic compilation
   bcpl program.bcpl
   
   # With optimization
   bcpl -O program.bcpl
   
   # Generate assembly listing  
   bcpl -S program.bcpl
   
   # Include debugging information
   bcpl -g program.bcpl
   
   # Specify output name
   bcpl program.bcpl -o myprogram
   
   # Multiple source files
   bcpl main.bcpl utils.bcpl -o program
   
   # Library linking
   bcpl program.bcpl -l mylib

Performance Examples
--------------------

Optimized BCPL code patterns:

.. code-block:: bcpl

   // Efficient string copying
   AND FAST_COPY(dest, src) BE
   $(
      LET len = src%0
      dest%0 := len
      
      // Word-aligned copying when possible
      FOR i = 1 TO len DO
         dest%i := src%i
   $)
   
   // Efficient table lookup
   AND TABLE_LOOKUP(table, key) = VALOF
   $(
      // Binary search for sorted tables
      LET low, high = 1, table!0
      
      WHILE low <= high DO
      $(
         LET mid = (low + high) / 2
         LET entry = table + mid * 2
         
         IF entry!0 = key THEN
            RESULTIS entry!1
         ELSE IF entry!0 < key THEN
            low := mid + 1
         ELSE
            high := mid - 1
      $)
      
      RESULTIS 0  // Not found
   $)
