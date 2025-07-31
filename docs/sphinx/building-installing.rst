Building and Installing
======================

This section describes how to build and install the BCPL compiler
on supported platforms.

System Requirements
------------------

The BCPL compiler requires:

* **Operating System**: Linux, FreeBSD, or macOS
* **Architecture**: x86-32, x86-64, or x86-16 (IA-16)
* **C Compiler**: Clang (required for C23 features)
* **Assembler**: GNU binutils (as)
* **Linker**: GNU binutils (ld)

Optional dependencies:

* **LLVM**: For experimental LLVM backend (version 10 or later)
* **CMake**: For modern build system (version 3.10 or later)
* **Doxygen**: For API documentation generation
* **Sphinx**: For user documentation

Quick Start
----------

For automated installation on supported platforms:

.. code-block:: bash

    # Clone the repository
    git clone https://github.com/example/bcpl-compiler.git
    cd bcpl-compiler

    # Build and install using the unified script
    ./build.sh
    sudo cmake --install build/Release

Manual Build Process
-------------------

Using Make
~~~~~~~~~

The traditional build system uses Make:

.. code-block:: bash

    # Build the compiler
    cd src
    make

    # Build development tools
    cd ../tools
    make

    # Run tests
    make test

    # Install (as root)
    cd ../src
    make install

Using CMake
~~~~~~~~~~

The modern build system uses CMake:

.. code-block:: bash

    # Configure build
    mkdir build
    cd build
    cmake ..

    # Build
    make

    # Test
    ctest

    # Install
    make install

Build Configuration
------------------

Target Architecture
~~~~~~~~~~~~~~~~~

The target architecture is controlled by the ``BITS`` variable:

.. code-block:: bash

    # 32-bit target
    make BITS=32

    # 64-bit target (default)
    make BITS=64

    # 16-bit target (IA-16)
    make BITS=16

Cross Compilation
~~~~~~~~~~~~~~~

For cross compilation, set the ``CROSS_PREFIX`` variable:

.. code-block:: bash

    # Cross compile for i686 Linux
    make CROSS_PREFIX=i686-linux-gnu-

    # Cross compile for Windows (MinGW)
    make CROSS_PREFIX=x86_64-w64-mingw32-

Installation Paths
~~~~~~~~~~~~~~~~~

Default installation paths:

* **Binaries**: ``/usr/local/bin/bcplc``
* **Runtime**: ``/usr/local/lib/bcplc/``
* **Documentation**: ``/usr/local/share/doc/bcplc/``
* **Man Pages**: ``/usr/local/man/man1/``

To change the installation prefix:

.. code-block:: bash

    # Make-based build
    make PREFIX=/opt/bcpl install

    # CMake-based build
    cmake -DCMAKE_INSTALL_PREFIX=/opt/bcpl ..

Testing the Installation
-----------------------

Verify the installation works correctly:

.. code-block:: bash

    # Test the compiler
    echo 'GET "LIBHDR" LET START() BE WRITES("Hello, BCPL!*N")' > hello.bcpl
    bcplc hello.bcpl
    ./hello

    # Run the comprehensive test suite
    cd tools
    make test

Expected output:

.. code-block:: text

    119 TESTS COMPLETED, 0 FAILURE(S)

Troubleshooting
--------------

Common Build Issues
~~~~~~~~~~~~~~~~~

**Clang not found**:
Ensure Clang is installed and in PATH. On Ubuntu/Debian:

.. code-block:: bash

    sudo apt-get install clang

**Missing dependencies**:
Install required development packages:

.. code-block:: bash

    # Ubuntu/Debian
    sudo apt-get install build-essential clang binutils

    # RedHat/CentOS
    sudo yum install clang binutils-devel

**Cross compilation failures**:
Ensure cross-compilation toolchain is properly installed:

.. code-block:: bash

    # Install MinGW for Windows cross compilation
    sudo apt-get install gcc-mingw-w64

Runtime Issues
~~~~~~~~~~~~~

**Segmentation fault on startup**:
- Check that the correct runtime files are installed
- Verify that BITS setting matches the target architecture
- Ensure sufficient stack space is available

**Missing runtime functions**:
- Verify that blib.o and related runtime files are properly installed
- Check that the linker is finding the correct library files

Advanced Configuration
---------------------

Environment Variables
~~~~~~~~~~~~~~~~~~~

The compiler recognizes several environment variables:

* ``PREFIX``: Installation prefix override
* ``BITS``: Target architecture (16, 32, or 64)  
* ``CROSS_PREFIX``: Cross-compilation toolchain prefix
* ``CC``: C compiler override (must be Clang-compatible)

Debugging Builds
~~~~~~~~~~~~~~~

For debugging the compiler itself:

.. code-block:: bash

    # Debug build with symbols
    make CFLAGS="-g -O0 -DDEBUG"

    # Verbose compilation
    make V=1

Custom Runtime Configuration
~~~~~~~~~~~~~~~~~~~~~~~~~~

The runtime can be customized by modifying configuration in ``src/su.s``:

.. code-block:: asm

    .set STKSIZ,0x400000    # BCPL stack size (4MB)

Rebuild the runtime after changes:

.. code-block:: bash

    cd src
    make clean
    make

Documentation Generation
-----------------------

Generate API documentation:

.. code-block:: bash

    # Generate Doxygen documentation
    doxygen Doxyfile

    # Generate Sphinx documentation  
    cd docs/sphinx
    make html

The generated documentation will be in:

* **Doxygen**: ``docs/doxygen/html/index.html``
* **Sphinx**: ``docs/sphinx/_build/html/index.html``
