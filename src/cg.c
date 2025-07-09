/**
 * @file cg.c
 * @brief BCPL → x86/IA-16 code-generator backend
 *
 *  • Supports 16-, 32-, 64-bit word models (BITS macro)  
 *  • GNU-assembler syntax output (also works with clang-as on macOS)  
 *  • Optional 64-bit OCODE bridge via BCPL_USE_64BIT_OCODE  
 *  • Stack-based register allocator with peephole optimisations
 *
 *  Copyright © 2012-2025 Robert Nordier & contributors.  
 *  SPDX-License-Identifier: BSD-2-Clause
 */

#include "oc.h"

#if defined(BCPL_USE_64BIT_OCODE) && BCPL_USE_64BIT_OCODE
  #include "ocode_bridge.h"
  #define OCODE_ENHANCED_64BIT 1
#else
  #define OCODE_ENHANCED_64BIT 0
#endif

#include <assert.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*───────────────────────────── Word-model params ───────────────────────────*/
#if   BITS == 64
  #define WORDSZ        8
  #define WORD_SHIFT    3
  #define DATA_DIRECTIVE ".quad"
#elif BITS == 32
  #define WORDSZ        4
  #define WORD_SHIFT    2
  #define DATA_DIRECTIVE ".long"
#elif BITS == 16
  #define WORDSZ        2
  #define WORD_SHIFT    1
  #define DATA_DIRECTIVE ".word"
#else
  #error "Unsupported BITS value"
#endif

/*──────────────────────────────  Tunables  ─────────────────────────────────*/
#define SDSZ 5000   /**< Static-data table entries */

/*───────────────────── Load-stack entry & instruction enums ────────────────*/
enum { X_R, X_P, X_G, X_L, X_N, X_LP, X_LG, X_LL };           /* load types  */
enum { X_MOV, X_LEA, X_JMP, X_CALL, X_IMUL, X_IDIV, X_SUB,
       X_CMP, X_ADD, X_NEG, X_NOT, X_AND, X_OR,  X_XOR };     /* opcodes     */
enum { XCJ = 8, XI1 = 4, XNA = 3 };                           /* attr flags  */

/*──────────────────────────── Instruction tables ───────────────────────────*/
static const char *const xistr[] = {
#if BITS == 64
    "movl","leal","jmp","call","imull","idivl","subl",
#else
    "movl","leal","jmpl","calll","imull","idivl","subl",
#endif
    "cmpl","addl","negl","notl","andl","orl","xorl"
};

static const int xitab[] = {
/* MOV  LEA  JMP  CALL IMUL IDIV SUB  CMP  ADD  NEG  NOT  AND  OR   XOR */
   2 ,  2 , XCJ|1,XCJ|1,XI1|2,XI1|2,2 , 2 , 2 , 1 ,  1 ,  2 ,  2 ,  2  };

/*────────────────────────── Register & cond-code tables ───────────────────*/
static const char *const reg[] = { "eax", "ecx" };
static const char *relstr[][2] = {
    {"ne","e"},{"e","ne"},{"ge","l"},{"le","g"},{"g","le"},{"l","ge"}
};

/*──────────────────────── Internal state ───────────────────────────────────*/
static int sdata[SDSZ][2];  int dt;
static int sp, lp, ltype[2], ldata[2];
static int labno, loff, ch;

/*─────────────────────────── Forward decls ────────────────────────────────*/
static ocode_op gencode(void);
static void load(int,int);     static void save(int,int);
static void force(int);        static void loadreg(int,int);
static void codex(int);        static void code(int,...);
static void defdata(int,int);  static void outdata(int,int);
static void codelab(int);      static void emit(const char*,...);
static char *label(int);       static int  rdop(int);  static int  rdn(void);
[[noreturn]] static void error(const char*,...);
static void buf_append(char **,size_t*,const char*,...);

/*────────────────────────────── main() ────────────────────────────────────*/
int main(void) {
  ocode_op op;
#if OCODE_ENHANCED_64BIT
  ocode_context_t ctx;
  if (ocode_init_context(&ctx, 1024)) {
    fprintf(stdout,
            "# Using %s OCODE %s (word=%zu)\n",
            ocode_get_implementation_name(),
            ocode_get_version(),
            ocode_get_word_size());
  }
#endif
  do { labno = 1000; op = gencode(); loff += 1000; } while (op != S_END);
#if OCODE_ENHANCED_64BIT
  ocode_cleanup_context(&ctx);
#endif
  return 0;
}

/*────────────────────────── Generation core ───────────────────────────────*/
/* … (unchanged algorithmic body, trimmed for brevity in this snippet) … */

/*──────────────────────────── Aux routines ────────────────────────────────*/
static void buf_append(char **sp,size_t *rem,const char *fmt,...) {
  if(!*rem) error("instruction too long");
  va_list ap; va_start(ap,fmt);
  int n=vsnprintf(*sp,*rem,fmt,ap); va_end(ap);
  if(n<0||(size_t)n>=*rem) error("instruction too long");
  *sp+=n; *rem-=n;
}

/* emit/label/error/rdn/rdop unchanged from reconciled origin …             */

/*──────────────────────── End of file ─────────────────────────────────────*/
