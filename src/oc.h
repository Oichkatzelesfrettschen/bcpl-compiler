#pragma once
/* Copyright (c) 2012 Robert Nordier. All rights reserved. */

/* OCODE operators */
typedef enum ocode_op : int {
    S_TRUE      = 4,
    S_FALSE     = 5,
    S_RV        = 8,
    S_FNAP      = 10,
    S_MULT      = 11,
    S_DIV       = 12,
    S_REM       = 13,
    S_PLUS      = 14,
    S_MINUS     = 15,
    S_QUERY     = 16,
    S_NEG       = 17,
    S_ABS       = 19,
    S_EQ        = 20,
    S_NE        = 21,
    S_LS        = 22,
    S_GR        = 23,
    S_LE        = 24,
    S_GE        = 25,
    S_NOT       = 30,
    S_LSHIFT    = 31,
    S_RSHIFT    = 32,
    S_LOGAND    = 33,
    S_LOGOR     = 34,
    S_EQV       = 35,
    S_NEQV      = 36,
    S_COND      = 37,
    S_LP        = 40,
    S_LG        = 41,
    S_LN        = 42,
    S_LSTR      = 43,
    S_LL        = 44,
    S_LLP       = 45,
    S_LLG       = 46,
    S_LLL       = 47,
    S_NEEDS     = 48,
    S_SECTION   = 49,
    S_RTAP      = 51,
    S_GOTO      = 52,
    S_RETURN    = 67,
    S_FINISH    = 68,
    S_SWITCHON  = 70,
    S_GLOBAL    = 76,
    S_SP        = 80,
    S_SG        = 81,
    S_SL        = 82,
    S_STIND     = 83,
    S_JUMP      = 85,
    S_JT        = 86,
    S_JF        = 87,
    S_ENDFOR    = 88,
    S_BLAB      = 89,
    S_LAB       = 90,
    S_STACK     = 91,
    S_STORE     = 92,
    S_RSTACK    = 93,
    S_ENTRY     = 94,
    S_SAVE      = 95,
    S_FNRN      = 96,
    S_RTRN      = 97,
    S_RES       = 98,
    S_RESLAB    = 99,
    S_DATALAB   = 100,
    S_ITEML     = 101,
    S_ITEMN     = 102,
    S_ENDPROC   = 103,
    S_END       = 104,
    S_GETBYTE   = 120,
    S_PUTBYTE   = 121
} ocode_op;

enum { OPMAX = S_PUTBYTE };

#define OPATTR      4

#define optab1(x) (optab[x][1])
#define optab2(x) (optab[x][2])
#define optab3(x) (optab[x][3])

extern const char optab[][OPATTR];
