/**
 * @file pt.c
 * @brief Peephole optimizer pattern definitions for BCPL compiler
 * @author Robert Nordier
 * @date 2012
 *
 * This file contains pattern definitions used by the peephole optimizer
 * to improve generated assembly code. The patterns define common sequences
 * of instructions that can be replaced with more efficient equivalents.
 *
 * Each pattern array contains:
 * - Original instruction sequence to match
 * - Replacement instruction sequence (after NULL terminator)
 *
 * Pattern matching supports placeholders:
 * - @0, @1, @2, etc. - Parameter substitution
 * - @$n - Immediate value reference
 *
 * @see op.c for the pattern matching and replacement engine
 */

/* Copyright (c) 2012 Robert Nordier. All rights reserved. */

/* Patterns for peephole optimizer */

#include <stddef.h>

/** @brief Pattern for SWITCHON instruction optimization (case 0)
 *
 * Optimizes switch statement code generation by eliminating unnecessary
 * jumps when the switch has no cases.
 */
static const char *const p00[] = {"\tmovl @0,%eax\n",
                                  "\tmov @1,%edx\n",
                                  "\tmov $0,%ecx\n",
                                  "\tjecxz 2f\n",
                                  "1:\tcmp (%edx),%eax\n",
                                  "\tje 3f\n",
                                  "\tadd $8,%edx\n",
                                  "\tloop 1b\n",
                                  "2:\tjmp @2\n",
                                  "3:\tjmp *4(%edx)\n",
                                  NULL,
                                  "\tjmp @2\n",
                                  NULL};
/** @brief Pattern for SWITCHON instruction optimization
 *
 * Optimizes switch statement jump table lookups by eliminating
 * redundant conditional jumps.
 */
static const char *const p01[] = {"\tjecxz 2f\n", NULL, NULL};
/** @brief Pattern for equality comparison optimization
 *
 * Replaces movl/cmpl/je sequences with direct cmpl/je when possible,
 * eliminating unnecessary register loads for constant comparisons.
 */
static const char *const p02[] = {
    "\tmovl $@0,%eax\n", "\tcmpl @$1,%eax\n", "\tje @2\n", NULL,
    "\tcmpl $@0,@1\n",   "\tje @2\n",         NULL};
/** @brief Pattern for inequality comparison optimization
 *
 * Replaces movl/cmpl/jne sequences with direct cmpl/jne when possible,
 * eliminating unnecessary register loads for constant comparisons.
 */
static const char *const p03[] = {
    "\tmovl $@0,%eax\n", "\tcmpl @$1,%eax\n", "\tjne @2\n", NULL,
    "\tcmpl $@0,@1\n",   "\tjne @2\n",        NULL};
/** @brief Pattern for less-than comparison optimization
 *
 * Optimizes less-than comparisons by eliminating register loads
 * and reversing comparison operands when beneficial.
 */
static const char *const p04[] = {
    "\tmovl $@0,%eax\n", "\tcmpl @$1,%eax\n", "\tjl @2\n", NULL,
    "\tcmpl $@0,@1\n",   "\tjg @2\n",         NULL};
/** @brief Pattern for greater-than comparison optimization
 *
 * Optimizes greater-than comparisons by eliminating register loads
 * and reversing comparison operands when beneficial.
 */
static const char *const p05[] = {
    "\tmovl $@0,%eax\n", "\tcmpl @$1,%eax\n", "\tjg @2\n", NULL,
    "\tcmpl $@0,@1\n",   "\tjl @2\n",         NULL};
/** @brief Pattern for less-than-or-equal comparison optimization
 *
 * Optimizes less-than-or-equal comparisons by eliminating register loads
 * and reversing comparison operands when beneficial.
 */
static const char *const p06[] = {
    "\tmovl $@0,%eax\n", "\tcmpl @$1,%eax\n", "\tjle @2\n", NULL,
    "\tcmpl $@0,@1\n",   "\tjge @2\n",        NULL};
/** @brief Pattern for greater-than-or-equal comparison optimization
 *
 * Optimizes greater-than-or-equal comparisons by eliminating register loads
 * and reversing comparison operands when beneficial.
 */
static const char *const p07[] = {
    "\tmovl $@0,%eax\n", "\tcmpl @$1,%eax\n", "\tjge @2\n", NULL,
    "\tcmpl $@0,@1\n",   "\tjle @2\n",        NULL};
/** @brief Pattern for array access comparison optimization
 *
 * Combines array access and comparison into a single instruction,
 * eliminating the intermediate register load.
 */
static const char *const p08[] = {"\tmov (,%eax,4),%eax\n", "\tcmpl $@0,%eax\n",
                                  NULL, "\tcmpl $@0,(,%eax,4)\n", NULL};
/** @brief Pattern for array access register comparison optimization
 *
 * Combines array access and register comparison into a single instruction,
 * eliminating the intermediate register load.
 */
static const char *const p09[] = {"\tmov (,%eax,4),%eax\n", "\tcmpl %@0,%eax\n",
                                  NULL, "\tcmpl %@0,(,%eax,4)\n", NULL};
/** @brief Pattern for multiplication by 2 optimization
 *
 * Replaces multiplication by 2 with a left shift operation,
 * which is more efficient on most processors.
 */
static const char *const p10[] = {"\tmovl $2,%ecx\n", "\timull %ecx\n", NULL,
                                  "\tshll $1,%eax\n", NULL};
/** @brief Pattern for load-modify-store optimization
 *
 * Combines load-modify-store sequences into direct memory operations,
 * eliminating unnecessary register traffic.
 */
static const char *const p11[] = {"\tmovl @$0,%eax\n", "\t@1 %eax\n",
                                  "\tmovl %eax,@0\n",  NULL,
                                  "\t@1 @0\n",         NULL};
/** @brief Pattern for equality test with setcc optimization
 *
 * Optimizes equality comparisons that set condition codes,
 * eliminating unnecessary register loads for constant comparisons.
 */
static const char *const p16[] = {"\tmovl $@0,%eax\n",
                                  "\tcmpl @$1,%eax\n",
                                  "\tsete %al\n",
                                  NULL,
                                  "\tcmpl $@0,@1\n",
                                  "\tsete %al\n",
                                  NULL};
/** @brief Pattern for inequality test with setcc optimization
 *
 * Optimizes inequality comparisons that set condition codes,
 * eliminating unnecessary register loads for constant comparisons.
 */
static const char *const p17[] = {"\tmovl $@0,%eax\n",
                                  "\tcmpl @$1,%eax\n",
                                  "\tsetne %al\n",
                                  NULL,
                                  "\tcmpl $@0,@1\n",
                                  "\tsetne %al\n",
                                  NULL};
/** @brief Pattern for less-than test with setcc optimization
 *
 * Optimizes less-than comparisons that set condition codes,
 * eliminating register loads and reversing operands when beneficial.
 */
static const char *const p18[] = {"\tmovl $@0,%eax\n",
                                  "\tcmpl @$1,%eax\n",
                                  "\tsetl %al\n",
                                  NULL,
                                  "\tcmpl $@0,@1\n",
                                  "\tsetg %al\n",
                                  NULL};
/** @brief Pattern for greater-than test with setcc optimization
 *
 * Optimizes greater-than comparisons that set condition codes,
 * eliminating register loads and reversing operands when beneficial.
 */
static const char *const p19[] = {"\tmovl $@0,%eax\n",
                                  "\tcmpl @$1,%eax\n",
                                  "\tsetg %al\n",
                                  NULL,
                                  "\tcmpl $@0,@1\n",
                                  "\tsetl %al\n",
                                  NULL};
/* LE */
static const char *const p20[] = {"\tmovl $@0,%eax\n",
                                  "\tcmpl @$1,%eax\n",
                                  "\tsetle %al\n",
                                  NULL,
                                  "\tcmpl $@0,@1\n",
                                  "\tsetge %al\n",
                                  NULL};
/* GE */
static const char *const p21[] = {"\tmovl $@0,%eax\n",
                                  "\tcmpl @$1,%eax\n",
                                  "\tsetge %al\n",
                                  NULL,
                                  "\tcmpl $@0,@1\n",
                                  "\tsetle %al\n",
                                  NULL};
static const char *const p22[] = {"\tmovl @0,%eax\n", "\taddl $1,%eax\n",
                                  "\tmovl %eax,@0\n", NULL,
                                  "\tincl @0\n",      NULL};
static const char *const p23[] = {"\tmovl $1,%eax\n", "\taddl @0,%eax\n",
                                  "\tmovl %eax,@0\n", NULL,
                                  "\tincl @0\n",      NULL};
static const char *const p24[] = {"\tmovl @0,%eax\n", "\taddl $-1,%eax\n",
                                  "\tmovl %eax,@0\n", NULL,
                                  "\tdecl @0\n",      NULL};
static const char *const p25[] = {"\tmovl $-1,%eax\n", "\taddl @0,%eax\n",
                                  "\tmovl %eax,@0\n",  NULL,
                                  "\tdecl @0\n",       NULL};
static const char *const p26[] = {"\tmovl @0,%eax\n", "\tsubl $1,%eax\n",
                                  "\tmovl %eax,@0\n", NULL,
                                  "\tdecl @0\n",      NULL};
static const char *const p27[] = {"\tmovl @0,%eax\n", "\tsubl $-1,%eax\n",
                                  "\tmovl %eax,@0\n", NULL,
                                  "\tincl @0\n",      NULL};
static const char *const p28[] = {"\tmovl %@0,%eax\n", "\tcmpl @1,%eax\n", NULL,
                                  "\tcmpl @1,%@0\n", NULL};
/** @brief Pattern for memory comparison optimization
 *
 * Combines memory load and comparison into direct memory comparison,
 * eliminating intermediate register usage.
 */
static const char *const p29[] = {"\tmovl @$0,%eax\n", "\tcmpl $@1,%eax\n",
                                  NULL, "\tcmpl $@1,@0\n", NULL};
/** @brief Pattern for memory-register comparison optimization
 *
 * Combines memory load and register comparison into direct memory-register
 * comparison, eliminating intermediate register load.
 */
static const char *const p30[] = {"\tmovl @$0,%eax\n", "\tcmpl %@1,%eax\n",
                                  NULL, "\tcmpl %@1,@0\n", NULL};
/** @brief Pattern for increment optimization (add 1)
 *
 * Replaces movl $1 + addl sequence with movl + incl,
 * which is more efficient for incrementing by 1.
 */
static const char *const p31[] = {"\tmovl $1,@0\n", "\taddl @1,@0\n", NULL,
                                  "\tmovl @1,@0\n", "\tincl @0\n",    NULL};
/** @brief Pattern for decrement optimization (add -1)
 *
 * Replaces movl $-1 + addl sequence with movl + decl,
 * which is more efficient for decrementing by 1.
 */
static const char *const p32[] = {"\tmovl $-1,@0\n", "\taddl @1,@0\n", NULL,
                                  "\tmovl @1,@0\n",  "\tdecl @0\n",    NULL};
/** @brief Pattern for add-by-one optimization
 *
 * Replaces addl $1 with the more efficient incl instruction.
 */
static const char *const p33[] = {"\taddl $1,@0\n", NULL, "\tincl @0\n", NULL};
/** @brief Pattern for add-by-negative-one optimization
 *
 * Replaces addl $-1 with the more efficient decl instruction.
 */
static const char *const p34[] = {"\taddl $-1,@0\n", NULL, "\tdecl @0\n", NULL};
/** @brief Pattern for subtract-by-one optimization
 *
 * Replaces subl $1 with the more efficient decl instruction.
 */
static const char *const p35[] = {"\tsubl $1,@0\n", NULL, "\tdecl @0\n", NULL};
/** @brief Pattern for subtract-by-negative-one optimization
 *
 * Replaces subl $-1 (subtract negative one) with incl (increment),
 * which is equivalent but more efficient.
 */
static const char *const p36[] = {"\tsubl $-1,@0\n", NULL, "\tincl @0\n", NULL};
/** @brief Pattern for add-zero elimination
 *
 * Eliminates addl $0,%eax instructions which have no effect.
 */
static const char *const p37[] = {"\taddl $0,%eax\n", NULL, NULL};
static const char *const p38[] = {"\tmovl %eax,@0\n", "\tmovl @0,%eax\n", NULL,
                                  "\tmovl %eax,@0\n", NULL};
/** @brief Pattern for redundant load elimination
 *
 * Eliminates redundant load operations when a value is stored
 * and immediately loaded back from the same location.
 */
static const char *const p39[] = {"\tjmp L@0\n", "L@0:\n", NULL, "L@0:\n",
                                  NULL};
/** @brief Pattern for redundant jump elimination
 *
 * Eliminates jump instructions to the immediately following label,
 * which are unnecessary and waste execution time.
 */
static const char *const p40[] = {"\tmovl $1,%ecx\n", "\tshll %cl,%eax\n", NULL,
                                  "\tshll $1,%eax\n", NULL};
/** @brief Pattern for left shift by 1 optimization
 *
 * Replaces variable left shift by 1 with immediate left shift,
 * avoiding unnecessary register setup for the shift count.
 */
static const char *const p41[] = {"\tmovl $1,%ecx\n", "\tshrl %cl,%eax\n", NULL,
                                  "\tshrl $1,%eax\n", NULL};
/** @brief Pattern for right shift by 1 optimization
 *
 * Replaces variable right shift by 1 with immediate right shift,
 * avoiding unnecessary register setup for the shift count.
 */

const char *const *pat[] = {p00, p01, p02, p03, p04, p05, p06, p07, p08, p09,
                            p10, p11, p16, p17, p18, p19, p20, p21, p22, p23,
                            p24, p25, p26, p27, p28, p29, p30, p31, p32, p33,
                            p34, p35, p36, p37, p38, p39, p40, p41, NULL};
