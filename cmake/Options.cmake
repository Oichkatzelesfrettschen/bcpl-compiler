# cmake/Options.cmake
# Centralized build options for BCPL Compiler

# Analysis & Quality Tools
option(ENABLE_COVERAGE "Enable code coverage analysis" OFF)
option(ENABLE_VALGRIND "Enable Valgrind memory checking" OFF)
option(ENABLE_ASAN "Enable AddressSanitizer" OFF)
option(ENABLE_MSAN "Enable MemorySanitizer" OFF)
option(ENABLE_TSAN "Enable ThreadSanitizer" OFF)
option(ENABLE_UBSAN "Enable UndefinedBehaviorSanitizer" OFF)
option(ENABLE_CLANG_TIDY "Enable clang-tidy static analysis" OFF)
option(ENABLE_CLANG_ANALYZER "Enable Clang Static Analyzer" OFF)
option(ENABLE_CPPCHECK "Enable Cppcheck static analysis" OFF)

# Performance & Profiling
option(ENABLE_THIN_LTO "Enable ThinLTO optimization" OFF)
option(ENABLE_FULL_LTO "Enable Full LTO optimization" OFF)
option(ENABLE_VTUNE "Enable Intel VTune profiling support" OFF)
option(ENABLE_BENCHMARKS "Enable Google Benchmark performance tests" OFF)

# Fuzzing & Sanitization
option(ENABLE_FUZZING "Enable fuzzing with libFuzzer" OFF)
option(ENABLE_CFI "Enable Control Flow Integrity" OFF)

# Documentation
option(ENABLE_DOCS "Enable documentation generation" OFF)

# Performance variants
option(ENABLE_PGO "Enable Profile-Guided Optimization build" OFF)
option(ENABLE_MAX_PERF "Enable max hardware-specific performance build" OFF)
option(ENABLE_PORTABLE_PERF "Enable portable performance baseline build" OFF)

# Custom function to apply tooling flags to targets
function(apply_tooling_flags target)
  # Sanitizers
  if(ENABLE_ASAN)
    target_compile_options(${target} PRIVATE -fsanitize=address -fno-omit-frame-pointer)
    target_link_options(${target} PRIVATE -fsanitize=address)
  endif()
  if(ENABLE_UBSAN)
    target_compile_options(${target} PRIVATE -fsanitize=undefined)
    target_link_options(${target} PRIVATE -fsanitize=undefined)
  endif()
  if(ENABLE_TSAN)
    target_compile_options(${target} PRIVATE -fsanitize=thread)
    target_link_options(${target} PRIVATE -fsanitize=thread)
  endif()
  if(ENABLE_MSAN)
    target_compile_options(${target} PRIVATE -fsanitize=memory -fno-omit-frame-pointer)
    target_link_options(${target} PRIVATE -fsanitize=memory)
  endif()
  # LTO
  if(ENABLE_THIN_LTO)
    target_compile_options(${target} PRIVATE -flto=thin)
    target_link_options(${target} PRIVATE -flto=thin)
  elseif(ENABLE_FULL_LTO)
    target_compile_options(${target} PRIVATE -flto)
    target_link_options(${target} PRIVATE -flto)
  endif()
  # Coverage
  if(ENABLE_COVERAGE)
    target_compile_options(${target} PRIVATE --coverage -fprofile-arcs -ftest-coverage)
    target_link_options(${target} PRIVATE --coverage)
  endif()
  # Static analysis
  if(ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
    if(CLANG_TIDY_EXE)
      set_target_properties(${target} PROPERTIES
        C_CLANG_TIDY "${CLANG_TIDY_EXE};-checks=*,-modernize-*,-readability-magic-numbers"
      )
    endif()
  endif()
  # Control Flow Integrity
  if(ENABLE_CFI)
    target_compile_options(${target} PRIVATE -fsanitize=cfi -flto)
    target_link_options(${target} PRIVATE -fsanitize=cfi -flto)
  endif()
endfunction()

# Custom targets for analysis tools
if(ENABLE_COVERAGE)
  find_program(LCOV_PATH lcov)
  find_program(GENHTML_PATH genhtml)
  if(LCOV_PATH AND GENHTML_PATH)
    add_custom_target(coverage
      COMMAND ${LCOV_PATH} --directory . --capture --output-file coverage.info
      COMMAND ${LCOV_PATH} --remove coverage.info '/usr/*' --output-file coverage.info  
      COMMAND ${GENHTML_PATH} coverage.info --output-directory coverage_html
      COMMENT "Generating code coverage report"
    )
  endif()
endif()

if(ENABLE_VALGRIND)
  find_program(VALGRIND_PROGRAM valgrind)
  if(VALGRIND_PROGRAM)
    add_custom_target(valgrind
      COMMAND ${VALGRIND_PROGRAM} --tool=memcheck --leak-check=full --show-leak-kinds=all
      COMMENT "Running Valgrind memory analysis"
    )
  endif()
endif()

if(ENABLE_CPPCHECK)
  find_program(CPPCHECK_EXECUTABLE cppcheck)
  if(CPPCHECK_EXECUTABLE)
    add_custom_target(cppcheck
      COMMAND ${CPPCHECK_EXECUTABLE} --enable=all --std=c11 --force --quiet ${CMAKE_SOURCE_DIR}/src
      COMMENT "Running Cppcheck static analysis"
    )
  endif()
endif()
