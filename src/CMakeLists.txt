cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Build backend programs cg and op
add_executable(cg cg.c oc.c)
target_compile_definitions(cg PRIVATE BITS=64)
add_executable(op op.c pt.c)
target_compile_definitions(op PRIVATE BITS=64)

# Assemble the runtime in 64-bit mode
set(AS_FLAGS "--64" "--defsym" "BITS=64")
set(BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})

function(add_asm_object out src)
    add_custom_command(
        OUTPUT ${out}
        COMMAND as ${AS_FLAGS} -o ${out} ${src}
        DEPENDS ${src}
        WORKING_DIRECTORY ${BUILD_DIR}
        VERBATIM)
endfunction()

add_asm_object(${BUILD_DIR}/su.o ${SRC_DIR}/su.s)
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
add_asm_object(${BUILD_DIR}/sys.o ${SRC_DIR}/sys.s)

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
    COMMAND as ${AS_FLAGS} -o st.o ${ST_SRC}
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
    COMMAND ld -m elf_x86_64 -o st ${RUNTIME_OBJS}
    DEPENDS ${RUNTIME_OBJS}
    WORKING_DIRECTORY ${BUILD_DIR}
    VERBATIM)

add_custom_target(runtime ALL DEPENDS ${BUILD_DIR}/st)

# Installation
install(TARGETS cg op RUNTIME DESTINATION lib/bcplc)
install(PROGRAMS ${BUILD_DIR}/st DESTINATION lib/bcplc)
install(PROGRAMS bcplc DESTINATION bin)
install(FILES bcplc.1 DESTINATION share/man/man1)
install(FILES LIBHDR DESTINATION lib/bcplc)
install(FILES ${BUILD_DIR}/su.o ${BUILD_DIR}/blib.o ${BUILD_DIR}/global.o
              ${BUILD_DIR}/rt.o ${BUILD_DIR}/sys.o
        DESTINATION lib/bcplc)
