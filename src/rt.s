// Copyright (c) 2004, 2012 Robert Nordier. All rights reserved.

// BCPL compiler x86 runtime

.ifndef BITS
.set BITS,32
.endif

.if BITS==64
.macro PUSH32 reg
    sub $4,%rsp
    movl \reg,(%rsp)
.endm
.macro PUSH32m mem
    movl \mem,%eax
    sub $4,%rsp
    movl %eax,(%rsp)
.endm
.macro POP32 reg
    movl (%rsp),\reg
    add $4,%rsp
.endm
.else
.macro PUSH32 reg
    push \reg
.endm
.macro PUSH32m mem
    pushl \mem
.endm
.macro POP32 reg
    pop \reg
.endm
.endif

// The following two settings can be changed as desired
        .set    FCBCNT,8                # Number of FCBs
        .set    BUFSIZ,512              # I/O buffer size

// System interfacing constants
        .set    IFLAGS,0                # UNIX open flags (input)
        .set    MODE,0666               # UNIX open mode (output)
        .set    PGSZ,4096               # UNIX sbrk increment
        .set    STDIN,0                 # UNIX stdin
        .set    STDOUT,1                # UNIX stdout

// Miscellaneous
        .set    STRSIZ,256              # BCPL string size
        .set    FCBSIZ,20               # FCB size

// FCB structure
        .set    FCB.BF,0                # Buffer pointer
        .set    FCB.XP,4                # Extra pointer
        .set    FCB.CP,8                # Current pointer
        .set    FCB.FD,12               # File descriptor
        .set    FCB.FL,16               # Flags

// FCB flags (if flags are zero, FCB is unallocated)
        .set    FL.RD,1                 # Open for reading
        .set    FL.WR,2                 # Open for writing
        .set    FL.NB,4                 # No buffering
        .set    FL.EOF,64               # End of file
        .set    FL.ERR,128              # I/O error

// BCPL globals
        .set    HEAP,94                 # Internal heap pointer


// Called once by startup code.  Sets the buffer of each FCB,
// and associates the first two streams with stdin and stdout.

        .global rtinit
rtinit:
        mov     $ft,%ebx
        mov     $FCBCNT,%ecx
        mov     $bf,%eax
1:      mov     %eax,(%ebx)             # Set FCB buffer
        add     $BUFSIZ,%eax
        add     $FCBSIZ,%ebx
        loop    1b
        mov     $ft,%ebx
        mov     $STDIN,%eax             # Set up stdin
        mov     $FL.RD,%dl              #  as input
        call    fopen
        mov     $ft+FCBSIZ,%ebx
        mov     $STDOUT,%eax            # Set up stdout
        mov     $FL.WR,%dl              #  as output
        call    fopen
        ret

// Called once by startup code.  Closes each open stream.

        .global rtexit
rtexit:
        mov     $ft,%ebx
        mov     $FCBCNT,%ecx
1:      cmpb    $0,FCB.FL(%ebx)         # FCB not in use?
        je      2f
        PUSH32 %ecx
        call    fclose
        POP32 %ecx
2:      add     $FCBSIZ,%ebx
        loop    1b
        ret


// Sets up an FCB
// Entry: eax = file descriptor; ebx = FCB; dl = flags
// Exit: eax, ecx undefined

fopen:
        mov     %eax,FCB.FD(%ebx)       # Set file descriptor
        mov     FCB.BF(%ebx),%eax       # Initialize pointers
        mov     %eax,FCB.CP(%ebx)
        mov     %eax,FCB.XP(%ebx)
        mov     %dl,FCB.FL(%ebx)        # Set flags
        cmp     $FL.RD,%dl              # Open for reading?
        je      1f                      # Yes
        PUSH32m FCB.FD(%ebx)            # Is it a tty?
        call    isatty
        POP32 %ecx
        test    %eax,%eax
        jnz     1f                      # Yes
        addl    $BUFSIZ,FCB.XP(%ebx)    # Enable buffering
1:      ret

// Closes an FCB
// Entry: ebx = FCB
// Exit: eax, ecx, edx undefined

fclose:
        testb   $FL.WR,FCB.FL(%ebx)     # In write mode?
        jz      1f
        call    flush
1:      PUSH32m FCB.FD(%ebx)
        call    close
        POP32 %ecx
        movb    $0,FCB.FL(%ebx)         # Set as unused
        ret

// Flushes the stream buffer
// Entry: ebx = stream
// Exit: eax = 0/-1, ecx, edx undefined

flush:
        mov     FCB.CP(%ebx),%ecx
        mov     FCB.BF(%ebx),%edx
        mov     %edx,FCB.CP(%ebx)
        sub     %edx,%ecx               # Any bytes to write?
        jz      2f
1:      PUSH32 %ecx
        PUSH32 %edx
        PUSH32m FCB.FD(%ebx)
        call    write
        lea     12(%esp,1),%esp
        jc      3f
        add     %eax,%edx
        sub     %eax,%ecx
        jne     1b
2:      xor     %eax,%eax               # Result
        ret

3:      orb     $FL.ERR,FCB.FL(%ebx)    # Set error flag
        mov     $-1,%eax
        ret


// Standard BCPL routines and functions

// We assume a save size of 2.  On entry, ecx addresses the stack
// frame.  A result is returned in eax.  ebp, edi must be preserved:
// ebp addresses the caller's stack frame and edi the global vector.
// We preserve ebx and esi though they are not currently used by the
// CG.  eax, ecx, edx need not be preserved.

// SELECTINPUT(N)

SELECTINPUT:
        mov     8(%ecx),%eax
        mov     %eax,cis
        ret

// SELECTOUTPUT(N)

SELECTOUTPUT:
        mov     8(%ecx),%eax
        mov     %eax,cos
        ret

// CH := RDCH()

RDCH:
        PUSH32 %ebx
        mov     cis,%ebx
        mov     FCB.CP(%ebx),%ecx
        cmp     FCB.XP(%ebx),%ecx       # Still data in buffer?
        jb      1f                      # Yes
        mov     FCB.BF(%ebx),%ecx
        mov     %ecx,FCB.CP(%ebx)
        mov     %ecx,FCB.XP(%ebx)
        PUSH32 $BUFSIZ
        PUSH32 %ecx
        PUSH32m FCB.FD(%ebx)
        call    read
        lea     12(%esp,1),%esp
        jc      2f                      # If error
        test    %eax,%eax
        je      3f                      # If nothing read
        add     %eax,FCB.XP(%ebx)
1:      movzx   (%ecx),%eax
        inc     %ecx
        mov     %ecx,FCB.CP(%ebx)
        POP32 %ebx
        ret

2:      orb     $FL.ERR,FCB.FL(%ebx)    # Set error flag
        jmp     1f
3:      orb     $FL.EOF,FCB.FL(%ebx)    # Set EOF flag
1:      mov     $-1,%eax
        POP32 %ebx
        ret

// WRCH(CH)

WRCH:
        mov     8(%ecx),%eax
        PUSH32 %ebx
        mov     cos,%ebx
        mov     FCB.CP(%ebx),%ecx
        mov     %al,(%ecx)
        inc     %ecx
        mov     %ecx,FCB.CP(%ebx)
        cmp     FCB.XP(%ebx),%ecx
        jb      2f
        testb   $FL.NB,FCB.FL(%ebx)     # No buffering?
        jne     1f                      # Yes
        sub     FCB.BF(%ebx),%ecx
        cmp     $BUFSIZ,%ecx
        jae     1f
        cmp     $0xa,%al                # Linefeed ?
        jne     2f
1:      call    flush                   # Sets eax
2:      POP32 %ebx
        ret

// UNRDCH()

UNRDCH:
        mov     cis,%edx
        mov     FCB.CP(%edx),%ecx
        cmp     FCB.BF(%edx),%ecx
        je      1f
        dec     %ecx
        mov     %ecx,FCB.CP(%edx)
1:      ret

// STREAM := INPUT()

INPUT:
        mov     cis,%eax
        ret

// STREAM := OUTPUT()

OUTPUT:
        mov     cos,%eax
        ret

// STOP(N)

STOP:
        POP32 %eax
        mov     8(%ecx),%eax
        jmp     _stop

// P := LEVEL()

LEVEL:
        mov     %ebp,%eax
        ret

// LONGJUMP(P, L)

LONGJUMP:
        POP32 %eax
        mov     8(%ecx),%ebp
        jmp     *12(%ecx)

// REWIND()

REWIND:
        PUSH32 %ebx
        mov     cis,%ebx
        xor     %ecx,%ecx
        PUSH32 %ecx
        PUSH32 %ecx
        PUSH32m FCB.FD(%ebx)
        call    olseek
        POP32 %eax                    # File descriptor
        POP32 %ecx
        POP32 %ecx
        mov     $FL.RD,%dl
        call    fopen
        POP32 %ebx
        ret

// RESULT := APTOVEC(F, N)

APTOVEC:
        mov     12(%ecx),%edx
        mov     %edx,%eax
        inc     %eax
        shl     $2,%eax
        add     %ecx,%eax
        xchg    %ecx,%eax
        mov     %edx,12(%ecx)
        mov     %eax,%edx
        shr     $2,%eax
        mov     %eax,8(%ecx)
        jmp     *8(%edx)

// STREAM := FINDOUTPUT(S)

FINDOUTPUT:
        mov     oflags,%edx
        jmp     findio

// STREAM := FINDINPUT(S)

FINDINPUT:
        mov     $IFLAGS,%edx

findio:
        mov     8(%ecx),%eax
        PUSH32 %ebx
        PUSH32 %esi
        PUSH32 %edi
        mov     $ft,%ebx
        mov     $FCBCNT,%ecx
1:      cmpb    $0,FCB.FL(%ebx)         # Find a free FCB
        je      2f
        add     $FCBSIZ,%ebx
        loop    1b
1:      xor     %eax,%eax
        jmp     3f
2:      shl     $2,%eax
        mov     %eax,%esi
        sub     $STRSIZ,%esp
        mov     %esp,%edi
        PUSH32 $MODE
        PUSH32 %edx                    # Flags for open
        PUSH32 %edi
        lodsb                           # Convert BCPL string
        movzx   %al,%ecx
        rep     movsb
        mov     %cl,(%edi)
        call    open
        lea     12+STRSIZ(%esp),%esp
        jc      1b
        cmp     $IFLAGS,%edx
        mov     $FL.RD,%dl
        je      1f
        mov     $FL.WR,%dl
1:      call    fopen
        mov     %ebx,%eax               # Result
3:      POP32 %edi
        POP32 %esi
        POP32 %ebx
        ret

// ENDREAD()

ENDREAD:
        PUSH32 %ebx
        mov     cis,%ebx
        call    fclose
        xor     %eax,%eax
        mov     %eax,cis
        POP32 %ebx
        ret

// ENDWRITE()

ENDWRITE:
        PUSH32 %ebx
        mov     cos,%ebx
        call    fclose
        xor     %eax,%eax
        mov     %eax,cos
        POP32 %ebx
        ret

// I:= PACKSTRING(U, S)

PACKSTRING:
        PUSH32 %esi
        PUSH32 %edi
        mov     8(%ecx),%esi
        shl     $2,%esi
        mov     12(%ecx),%edi
        shl     $2,%edi
        lodsl
        movzx   %al,%edx
        mov     %edx,%ecx
        shr     $2,%edx
        movl    %ecx,(%edi,%edx,4)      # Zero last cell
        stosb
        jecxz   2f
1:      lodsl
        stosb
        loop    1b
2:      mov     %edx,%eax
        POP32 %edi
        POP32 %esi
        ret

// UNPACKSTRING(S, U)

UNPACKSTRING:
        PUSH32 %esi
        PUSH32 %edi
        mov     8(%ecx),%esi
        shl     $2,%esi
        mov     12(%ecx),%edi
        shl     $2,%edi
        xor     %eax,%eax
        lodsb
        stosl
        mov     %eax,%ecx
        jecxz   2f
1:      lodsb
        stosl
        loop    1b
2:      POP32 %edi
        POP32 %esi
        ret

// CH := GETBYTE(V, N)

GETBYTE:
        mov     8(%ecx),%eax
        shl     $2,%eax
        add     12(%ecx),%eax
        movzb   (%eax),%eax
        ret

// PUTBYTE(V, N, B)

PUTBYTE:
        mov     8(%ecx),%eax
        shl     $2,%eax
        add     12(%ecx),%eax
        mov     16(%ecx),%ecx
        mov     %cl,(%eax)
        ret

// V := GETVEC(SIZE)

GETVEC:
        PUSH32 %ebx
        mov     8(%ecx),%edx            # Size arg
        add     $3,%edx                 # 1 + overhead
        shl     $2,%edx                 # As bytes
        lea     HEAP*4(%edi),%ebx       # Free list
1:      mov     (%ebx),%eax             # Next block
        test    %eax,%eax               # End of list?
        jz      1f                      # Yes
        cmp     %edx,4(%eax)            # Big enough?
        jae     2f                      # Yes
        mov     %eax,%ebx               # Continue
        jmp     1b
1:      mov     %edx,%eax
        add     $PGSZ-1,%eax            # Round up
        and     $~(PGSZ-1),%eax
        PUSH32 %eax                    # Ask for memory
        call    sbrk
        POP32 %ecx
        jc      3f
        movl    $0,(%eax)               # Append to list
        mov     %ecx,4(%eax)
        mov     %eax,(%ebx)
2:      mov     4(%eax),%ecx            # Size of block
        sub     %edx,%ecx               # Less requested size
        cmp     $8,%ecx                 # Big enough for new block?
        jbe     1f                      # No
        mov     %ecx,4(%eax)            # Shrink block
        add     %ecx,%eax               # Point past it
        mov     %edx,4(%eax)            # Fill in size
        jmp     2f                      # Join common
1:      mov     (%eax),%ecx             # Remove block
        mov     %ecx,(%ebx)             #  from list
2:      shr     $2,%eax                 # To int pointer
        inc     %eax                    # Pass control
3:      inc     %eax                    #  info
        POP32 %ebx
        ret

// FREEVEC(V)

FREEVEC:
        mov     8(%ecx),%edx            # Vector arg
        sub     $2,%edx                 # Include MCB
        shl     $2,%edx                 # To bytes
        lea     HEAP*4(%edi),%eax       # Base MCB as next
1:      mov     %eax,%ecx               # Current MCB
        mov     (%ecx),%eax             # Get link
        test    %eax,%eax               # End of list?
        jz      1f                      # Yes
        cmp     %edx,%eax               # Next block above returned?
        jb      1b                      # No
1:      PUSH32 %ecx
        call    1f                      # Call ourselves
        mov     %edx,%eax
        POP32 %edx

# Absorb, or link to, the next block %eax to this block %edx

1:      mov     4(%edx),%ecx            # Our size
        add     %edx,%ecx               # Past ourselves
        cmp     %eax,%ecx               # Contiguous?
        jne     1f                      # No
        mov     4(%eax),%ecx            # Add next size
        add     %ecx,4(%edx)            #  to our size
        mov     (%eax),%eax             # Next link
1:      mov     %eax,(%edx)             # Set our link
        ret


        .data
cis:    .long   ft                      # CIS
cos:    .long   ft+FCBSIZ               # COS

        .comm   ft,FCBCNT*FCBSIZ        # FCBs
        .comm   bf,FCBCNT*BUFSIZ        # Buffers


        .global G11; .equ G11,SELECTINPUT
        .global G12; .equ G12,SELECTOUTPUT
        .global G13; .equ G13,RDCH
        .global G14; .equ G14,WRCH
        .global G15; .equ G15,UNRDCH
        .global G16; .equ G16,INPUT
        .global G17; .equ G17,OUTPUT
        .global G30; .equ G30,STOP
        .global G31; .equ G31,LEVEL
        .global G32; .equ G32,LONGJUMP
        .global G35; .equ G35,REWIND
        .global G40; .equ G40,APTOVEC
        .global G41; .equ G41,FINDOUTPUT
        .global G42; .equ G42,FINDINPUT
        .global G46; .equ G46,ENDREAD
        .global G47; .equ G47,ENDWRITE
        .global G66; .equ G66,PACKSTRING
        .global G67; .equ G67,UNPACKSTRING
        .global G85; .equ G85,GETBYTE
        .global G86; .equ G86,PUTBYTE
        .global G87; .equ G87,GETVEC
        .global G88; .equ G88,FREEVEC
