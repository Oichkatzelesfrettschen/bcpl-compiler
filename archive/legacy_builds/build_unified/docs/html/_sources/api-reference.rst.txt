API Reference
=============

This section provides detailed API documentation for all components
of the BCPL compiler system.

.. doxygenindex::

Core Components
--------------

OCODE Definitions
~~~~~~~~~~~~~~~~

.. doxygenfile:: oc.h

.. doxygenfile:: oc.c

Code Generator
~~~~~~~~~~~~~

.. doxygenfile:: cg.c

Optimizer
~~~~~~~~

.. doxygenfile:: op.c

LLVM Backend
~~~~~~~~~~~

.. doxygenfile:: llcg.c

Runtime System
--------------

Startup Code
~~~~~~~~~~~

.. doxygenfile:: su.s

System Interface
~~~~~~~~~~~~~~~

.. doxygenfile:: sys.s

Standard Library
~~~~~~~~~~~~~~~

.. doxygenfile:: blib.bcpl

Development Tools
----------------

Compiler Test Suite
~~~~~~~~~~~~~~~~~~

.. doxygenfile:: cmpltest.bcpl

Cross Reference Tool
~~~~~~~~~~~~~~~~~~

.. doxygenfile:: xref.bcpl

Memory Pattern Tool
~~~~~~~~~~~~~~~~~

.. doxygenfile:: gpm.bcpl
