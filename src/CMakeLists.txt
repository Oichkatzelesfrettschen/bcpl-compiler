cmake_minimum_required(VERSION 3.10)
if(NOT CMAKE_C_COMPILER_ID STREQUAL "Clang")
    message(FATAL_ERROR "Clang is required to build bcplc")
endif()
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Build backend programs cg and op
add_executable(cg cg.c oc.c)
target_compile_definitions(cg PRIVATE BITS=${BITS})
add_executable(op op.c pt.c)
target_compile_definitions(op PRIVATE BITS=${BITS})

# Optional LLVM backend llcg
find_package(LLVM QUIET CONFIG)
if(LLVM_FOUND)
    include_directories(${LLVM_INCLUDE_DIRS})
    add_definitions(${LLVM_DEFINITIONS})
    llvm_map_components_to_libnames(LLCG_LIBS
        core bitwriter native
    )
    add_executable(llcg llcg.c)
    target_link_libraries(llcg PRIVATE ${LLCG_LIBS})
    target_compile_definitions(llcg PRIVATE BITS=${BITS})
endif()

# Assemble the runtime
if(BITS STREQUAL "64")
    set(AS_FLAGS "--64" "--defsym" "BITS=64")
    set(LD_MODE "elf_x86_64")
elseif(BITS STREQUAL "32")
    set(AS_FLAGS "--32" "--defsym" "BITS=32")
    set(LD_MODE "elf_i386")
elseif(BITS STREQUAL "16")
    set(AS_FLAGS "--16" "--defsym" "BITS=16")
    set(LD_MODE "elf_i386")
else()
    message(FATAL_ERROR "Unsupported BITS value: ${BITS}")
endif()

set(AS "${CROSS_PREFIX}as")
set(LD "${CROSS_PREFIX}ld")
set(BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})

function(add_asm_object out src)
    add_custom_command(
        OUTPUT ${out}
        COMMAND ${AS} ${AS_FLAGS} -o ${out} ${src}
        DEPENDS ${src}
        WORKING_DIRECTORY ${BUILD_DIR}
        VERBATIM)
endfunction()

if(BITS STREQUAL "16")
    set(SU_SRC ${SRC_DIR}/su16.s)
    set(SYS_SRC ${SRC_DIR}/sys_ia16.s)
else()
    set(SU_SRC ${SRC_DIR}/su.s)
    set(SYS_SRC ${SRC_DIR}/sys.s)
endif()

add_asm_object(${BUILD_DIR}/su.o ${SU_SRC})
set(BLIB_SRC ${SRC_DIR}/blib.s)
if(BOOTSTRAP)
    add_custom_command(
        OUTPUT ${BUILD_DIR}/blib.s
        COMMAND bash -c "$<TARGET_FILE:cg> < ${SRC_DIR}/blib.O | $<TARGET_FILE:op> > blib.s"
        WORKING_DIRECTORY ${BUILD_DIR}
        DEPENDS cg op ${SRC_DIR}/blib.O
        VERBATIM)
    set(BLIB_SRC ${BUILD_DIR}/blib.s)
endif()
add_asm_object(${BUILD_DIR}/blib.o ${BLIB_SRC})
add_asm_object(${BUILD_DIR}/global.o ${SRC_DIR}/global.s)
add_asm_object(${BUILD_DIR}/rt.o ${SRC_DIR}/rt.s)
add_asm_object(${BUILD_DIR}/sys.o ${SYS_SRC})

set(ST_SRC ${SRC_DIR}/st.s)
if(BOOTSTRAP)
    add_custom_command(
        OUTPUT ${BUILD_DIR}/st.s
        COMMAND bash -c "$<TARGET_FILE:cg> < ${SRC_DIR}/st.O | $<TARGET_FILE:op> > st.s"
        WORKING_DIRECTORY ${BUILD_DIR}
        DEPENDS cg op ${SRC_DIR}/st.O
        VERBATIM)
    set(ST_SRC ${BUILD_DIR}/st.s)
endif()

add_custom_command(
    OUTPUT ${BUILD_DIR}/st.o
    COMMAND ${AS} ${AS_FLAGS} -o st.o ${ST_SRC}
    DEPENDS ${ST_SRC}
    WORKING_DIRECTORY ${BUILD_DIR}
    VERBATIM)

set(RUNTIME_OBJS
    ${BUILD_DIR}/su.o
    ${BUILD_DIR}/st.o
    ${BUILD_DIR}/blib.o
    ${BUILD_DIR}/global.o
    ${BUILD_DIR}/rt.o
    ${BUILD_DIR}/sys.o)

add_custom_command(
    OUTPUT ${BUILD_DIR}/st
    COMMAND ${LD} -m ${LD_MODE} -o st ${RUNTIME_OBJS}
    DEPENDS ${RUNTIME_OBJS}
    WORKING_DIRECTORY ${BUILD_DIR}
    VERBATIM)

add_custom_target(runtime ALL DEPENDS ${BUILD_DIR}/st)

# Installation
install(TARGETS cg op RUNTIME DESTINATION lib/bcplc)
if(TARGET llcg)
    install(TARGETS llcg RUNTIME DESTINATION lib/bcplc)
endif()
install(PROGRAMS ${BUILD_DIR}/st DESTINATION lib/bcplc)
install(PROGRAMS bcplc DESTINATION bin)
install(FILES bcplc.1 DESTINATION share/man/man1)
install(FILES LIBHDR DESTINATION lib/bcplc)
install(FILES ${BUILD_DIR}/su.o ${BUILD_DIR}/blib.o ${BUILD_DIR}/global.o
              ${BUILD_DIR}/rt.o ${BUILD_DIR}/sys.o
        DESTINATION lib/bcplc)
