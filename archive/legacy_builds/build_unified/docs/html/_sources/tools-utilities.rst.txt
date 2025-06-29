Tools and Utilities
===================

The BCPL compiler includes various development tools and utilities to aid in 
program development, testing, and maintenance.

Compiler Tools
--------------

**cmpltest.bcpl**
   Comprehensive test suite for the compiler:
   
   * Automated testing framework
   * Regression test collection
   * Performance benchmarks
   * Correctness verification
   
   Usage:
   
   .. code-block:: bash
   
      # Run all tests
      bcpl cmpltest.bcpl
      
      # Run specific test categories
      bcpl cmpltest.bcpl -syntax
      bcpl cmpltest.bcpl -codegen

**Cross-Reference Tool (xref.bcpl)**
   Generates cross-reference listings:
   
   * Symbol usage analysis
   * Procedure call graphs
   * Include file dependencies
   * Symbol definition locations
   
   Features:
   
   * HTML output format
   * Interactive browsing
   * Search and filtering
   * Export capabilities

**General Purpose Manager (gpm.bcpl)**
   Project build and management utility:
   
   * Dependency tracking
   * Incremental compilation
   * Build script execution
   * Configuration management

Build System
------------

**CMake Support** (CMakeLists.txt)
   Modern build system integration:
   
   * Cross-platform build configuration
   * Dependency management
   * Testing framework integration
   * Installation rules
   
   Example usage:
   
   .. code-block:: bash
   
      mkdir build
      cd build
      cmake ..
      make
      make install

**Makefile Support**
   Traditional make-based builds:
   
   * Platform-specific rules
   * Optimization level control
   * Debug/release configurations
   * Clean and install targets

Development Scripts
-------------------

**check-deps.sh**
   Dependency verification script:
   
   * Checks for required tools
   * Verifies library versions
   * Reports missing dependencies
   * Suggests installation commands

**hog_test.sh**
   Memory usage testing:
   
   * Stress testing with large inputs
   * Memory leak detection
   * Performance profiling
   * Resource usage monitoring

**makeall.sh**
   Complete build automation:
   
   * Builds all components
   * Runs test suites
   * Generates documentation
   * Creates distribution packages

**setup.sh**
   Development environment setup:
   
   * Configures build environment
   * Sets up development tools
   * Initializes workspace
   * Downloads dependencies

Testing Framework
-----------------

**Test Categories**
   The test suite covers:
   
   * **Syntax tests**: Parser correctness
   * **Semantic tests**: Type checking and scoping
   * **Code generation tests**: Output verification
   * **Runtime tests**: Execution correctness
   * **Performance tests**: Speed and memory usage

**Test Execution**
   * Automated test running
   * Result comparison
   * Failure reporting
   * Regression detection

**Test Data**
   * Positive test cases (should compile/run)
   * Negative test cases (should fail)
   * Edge cases and boundary conditions
   * Performance benchmarks

Debugging Tools
---------------

**GDB Integration** (gdb_commands.txt)
   Debugger command scripts:
   
   * Common debugging sequences
   * BCPL-specific pretty printers
   * Backtrace enhancement
   * Variable inspection helpers

**Debug Builds**
   Special compilation modes:
   
   * Symbol table generation
   * Debug information inclusion
   * Runtime checking enabled
   * Optimization disabled

Documentation Tools
-------------------

**Doxygen Integration**
   API documentation generation:
   
   * Function documentation
   * Data structure descriptions
   * Cross-references
   * Call graphs

**Sphinx Documentation**
   User and developer guides:
   
   * Tutorial content
   * Architecture descriptions
   * API references
   * Build instructions

Code Quality Tools
------------------

**Static Analysis**
   Code quality checking:
   
   * Lint-style warnings
   * Style compliance checking
   * Dead code detection
   * Complexity analysis

**Formatting Tools**
   Code formatting utilities:
   
   * Consistent indentation
   * Style guide enforcement
   * Automatic formatting
   * Configuration management

Distribution Tools
------------------

**Packaging Scripts**
   Distribution creation:
   
   * Source packages
   * Binary distributions
   * Installation packages
   * Dependency bundling

**Port Management** (ports/)
   Platform-specific adaptations:
   
   * Operating system ports
   * Architecture adaptations
   * Feature availability mapping
   * Configuration templates

Usage Examples
--------------

**Basic Compilation**
   .. code-block:: bash
   
      # Compile a BCPL program
      bcpl hello.bcpl
      
      # Compile with optimization
      bcpl -O hello.bcpl
      
      # Generate assembly listing
      bcpl -S hello.bcpl

**Development Workflow**
   .. code-block:: bash
   
      # Set up development environment
      ./setup.sh
      
      # Build everything
      ./makeall.sh
      
      # Run tests
      bcpl cmpltest.bcpl
      
      # Check dependencies
      ./check-deps.sh

**Documentation Generation**
   .. code-block:: bash
   
      # Generate API docs
      doxygen
      
      # Build user manual
      cd docs/sphinx
      make html

Tool Configuration
------------------

**Environment Variables**
   Key configuration variables:
   
   * ``BCPL_PATH``: Library search path
   * ``BCPL_OPTIONS``: Default compiler options
   * ``BCPL_DEBUG``: Debug mode control

**Configuration Files**
   * ``.bcplrc``: User configuration
   * ``OPT``: Compiler options
   * Build configuration files
