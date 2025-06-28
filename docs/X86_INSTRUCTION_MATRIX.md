# Phase I: Unified x86 Instruction/Mnemonic Matrix
# Complete ISA Reference: 16-bit/32-bit/64-bit (8086 → AVX-512 + AMX)

**Organization:** Functional Class → Encoding Family → Architectural Mode  
**Sources:** Intel Vol. 2A/2B, AMD Vol. 3/4, Microarchitecture Analysis  
**Target:** Complete opcode matrix for compiler backend generation

---

## I. DATA MOVEMENT INSTRUCTIONS

### A. General Register Transfers

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **MOV**  | 88-8B  | Legacy   | All   | r/m,r    | Move register/memory | 1 cycle |
|          | B0-BF  | Legacy   | All   | r,imm    | Move immediate to register | 1 cycle |
|          | C6-C7  | Legacy   | All   | r/m,imm  | Move immediate to r/m | 1 cycle |
| **MOVZX**| 0F B6  | Legacy   | 32/64 | r,r/m8   | Move with zero extension | 1 cycle |
|          | 0F B7  | Legacy   | 32/64 | r,r/m16  | Move with zero extension | 1 cycle |
| **MOVSX**| 0F BE  | Legacy   | 32/64 | r,r/m8   | Move with sign extension | 1 cycle |
|          | 0F BF  | Legacy   | 32/64 | r,r/m16  | Move with sign extension | 1 cycle |
|          | 63     | REX      | 64    | r64,r/m32| Move with sign extension | 1 cycle |
| **XCHG** | 86-87  | Legacy   | All   | r/m,r    | Exchange register/memory | 3 cycles |
|          | 90-97  | Legacy   | All   | rAX,r    | Exchange with accumulator | 3 cycles |

### B. Stack Operations

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **PUSH** | 50-57  | Legacy   | All   | r        | Push register | 1 cycle |
|          | FF/6   | Legacy   | All   | r/m      | Push register/memory | 1-3 cycles |
|          | 68     | Legacy   | All   | imm32    | Push immediate | 1 cycle |
|          | 6A     | Legacy   | All   | imm8     | Push immediate (sign-ext) | 1 cycle |
| **POP**  | 58-5F  | Legacy   | All   | r        | Pop to register | 1 cycle |
|          | 8F/0   | Legacy   | All   | r/m      | Pop to register/memory | 1-3 cycles |
| **PUSHF**| 9C     | Legacy   | All   | -        | Push flags | 2 cycles |
| **POPF** | 9D     | Legacy   | All   | -        | Pop flags | 3 cycles |

### C. Load Effective Address

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **LEA**  | 8D     | Legacy   | All   | r,m      | Load effective address | 1 cycle |

---

## II. ARITHMETIC INSTRUCTIONS

### A. Integer Arithmetic

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **ADD**  | 00-05  | Legacy   | All   | r/m,r/imm| Add | 1 cycle |
| **ADC**  | 10-15  | Legacy   | All   | r/m,r/imm| Add with carry | 1 cycle |
| **SUB**  | 28-2D  | Legacy   | All   | r/m,r/imm| Subtract | 1 cycle |
| **SBB**  | 18-1D  | Legacy   | All   | r/m,r/imm| Subtract with borrow | 1 cycle |
| **INC**  | 40-47  | Legacy   | 16/32 | r        | Increment register | 1 cycle |
|          | FF/0   | Legacy   | All   | r/m      | Increment register/memory | 1-3 cycles |
| **DEC**  | 48-4F  | Legacy   | 16/32 | r        | Decrement register | 1 cycle |
|          | FF/1   | Legacy   | All   | r/m      | Decrement register/memory | 1-3 cycles |
| **NEG**  | F6-F7/3| Legacy   | All   | r/m      | Two's complement negate | 1 cycle |

### B. Multiplication/Division

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **MUL**  | F6-F7/4| Legacy   | All   | r/m      | Unsigned multiply | 3-4 cycles |
| **IMUL** | F6-F7/5| Legacy   | All   | r/m      | Signed multiply | 3-4 cycles |
|          | 0F AF  | Legacy   | 32/64 | r,r/m    | Signed multiply | 3 cycles |
|          | 69     | Legacy   | 32/64 | r,r/m,imm| Signed multiply immediate | 3 cycles |
|          | 6B     | Legacy   | 32/64 | r,r/m,imm8| Signed multiply immediate | 3 cycles |
| **DIV**  | F6-F7/6| Legacy   | All   | r/m      | Unsigned divide | 20-40 cycles |
| **IDIV** | F6-F7/7| Legacy   | All   | r/m      | Signed divide | 20-40 cycles |

---

## III. LOGICAL INSTRUCTIONS

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **AND**  | 20-25  | Legacy   | All   | r/m,r/imm| Bitwise AND | 1 cycle |
| **OR**   | 08-0D  | Legacy   | All   | r/m,r/imm| Bitwise OR | 1 cycle |
| **XOR**  | 30-35  | Legacy   | All   | r/m,r/imm| Bitwise XOR | 1 cycle |
| **NOT**  | F6-F7/2| Legacy   | All   | r/m      | Bitwise complement | 1 cycle |
| **TEST** | 84-85  | Legacy   | All   | r/m,r    | Logical compare | 1 cycle |
|          | A8-A9  | Legacy   | All   | AL/AX,imm| Test accumulator | 1 cycle |
|          | F6-F7/0| Legacy   | All   | r/m,imm  | Test immediate | 1 cycle |

---

## IV. SHIFT AND ROTATE INSTRUCTIONS

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **SHL**  | C0-C1/4| Legacy   | All   | r/m,imm8 | Shift left | 1 cycle |
|          | D0-D1/4| Legacy   | All   | r/m,1    | Shift left by 1 | 1 cycle |
|          | D2-D3/4| Legacy   | All   | r/m,CL   | Shift left by CL | 1-3 cycles |
| **SHR**  | C0-C1/5| Legacy   | All   | r/m,imm8 | Shift right | 1 cycle |
|          | D0-D1/5| Legacy   | All   | r/m,1    | Shift right by 1 | 1 cycle |
|          | D2-D3/5| Legacy   | All   | r/m,CL   | Shift right by CL | 1-3 cycles |
| **SAR**  | C0-C1/7| Legacy   | All   | r/m,imm8 | Arithmetic right shift | 1 cycle |
| **ROL**  | C0-C1/0| Legacy   | All   | r/m,imm8 | Rotate left | 1 cycle |
| **ROR**  | C0-C1/1| Legacy   | All   | r/m,imm8 | Rotate right | 1 cycle |
| **RCL**  | C0-C1/2| Legacy   | All   | r/m,imm8 | Rotate through carry left | 1 cycle |
| **RCR**  | C0-C1/3| Legacy   | All   | r/m,imm8 | Rotate through carry right | 1 cycle |

---

## V. CONTROL FLOW INSTRUCTIONS

### A. Unconditional Jumps

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **JMP**  | EB     | Legacy   | All   | rel8     | Short jump | 1-2 cycles |
|          | E9     | Legacy   | All   | rel16/32 | Near jump | 1-2 cycles |
|          | FF/4   | Legacy   | All   | r/m      | Indirect near jump | 2-3 cycles |
|          | EA     | Legacy   | 16/32 | ptr16:16/32| Far jump | 10+ cycles |
|          | FF/5   | Legacy   | All   | m        | Indirect far jump | 10+ cycles |

### B. Conditional Jumps

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **JZ/JE**| 74     | Legacy   | All   | rel8     | Jump if zero/equal | 1-2 cycles |
|          | 0F 84  | Legacy   | All   | rel16/32 | Jump if zero/equal | 1-2 cycles |
| **JNZ/JNE**| 75   | Legacy   | All   | rel8     | Jump if not zero/equal | 1-2 cycles |
|          | 0F 85  | Legacy   | All   | rel16/32 | Jump if not zero/equal | 1-2 cycles |
| **JC/JB**| 72     | Legacy   | All   | rel8     | Jump if carry/below | 1-2 cycles |
| **JNC/JAE**| 73   | Legacy   | All   | rel8     | Jump if no carry/above equal | 1-2 cycles |
| **JS**   | 78     | Legacy   | All   | rel8     | Jump if sign | 1-2 cycles |
| **JNS**  | 79     | Legacy   | All   | rel8     | Jump if no sign | 1-2 cycles |
| **JO**   | 70     | Legacy   | All   | rel8     | Jump if overflow | 1-2 cycles |
| **JNO**  | 71     | Legacy   | All   | rel8     | Jump if no overflow | 1-2 cycles |

### C. Subroutine Calls

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **CALL** | E8     | Legacy   | All   | rel16/32 | Near call | 2-3 cycles |
|          | FF/2   | Legacy   | All   | r/m      | Indirect near call | 3-4 cycles |
|          | 9A     | Legacy   | 16/32 | ptr16:16/32| Far call | 10+ cycles |
|          | FF/3   | Legacy   | All   | m        | Indirect far call | 10+ cycles |
| **RET**  | C3     | Legacy   | All   | -        | Near return | 2-3 cycles |
|          | C2     | Legacy   | All   | imm16    | Near return + pop | 2-3 cycles |
|          | CB     | Legacy   | All   | -        | Far return | 10+ cycles |
|          | CA     | Legacy   | All   | imm16    | Far return + pop | 10+ cycles |

---

## VI. STRING INSTRUCTIONS

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **MOVSB**| A4     | Legacy   | All   | -        | Move string byte | 1-3 cycles |
| **MOVSW**| A5     | Legacy   | 16    | -        | Move string word | 1-3 cycles |
| **MOVSD**| A5     | Legacy   | 32    | -        | Move string dword | 1-3 cycles |
| **MOVSQ**| A5     | REX.W    | 64    | -        | Move string qword | 1-3 cycles |
| **CMPSB**| A6     | Legacy   | All   | -        | Compare string byte | 1-3 cycles |
| **SCASB**| AE     | Legacy   | All   | -        | Scan string byte | 1-3 cycles |
| **STOSB**| AA     | Legacy   | All   | -        | Store string byte | 1-3 cycles |
| **LODSB**| AC     | Legacy   | All   | -        | Load string byte | 1-3 cycles |

**String Prefixes:**
- **REP** (F3): Repeat while CX ≠ 0
- **REPE/REPZ** (F3): Repeat while equal/zero
- **REPNE/REPNZ** (F2): Repeat while not equal/not zero

---

## VII. BIT MANIPULATION INSTRUCTIONS

### A. Legacy Bit Operations

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **BT**   | 0F A3  | Legacy   | All   | r/m,r    | Bit test | 1 cycle |
|          | 0F BA/4| Legacy   | All   | r/m,imm8 | Bit test | 1 cycle |
| **BTS**  | 0F AB  | Legacy   | All   | r/m,r    | Bit test and set | 1 cycle |
|          | 0F BA/5| Legacy   | All   | r/m,imm8 | Bit test and set | 1 cycle |
| **BTR**  | 0F B3  | Legacy   | All   | r/m,r    | Bit test and reset | 1 cycle |
| **BTC**  | 0F BB  | Legacy   | All   | r/m,r    | Bit test and complement | 1 cycle |
| **BSF**  | 0F BC  | Legacy   | All   | r,r/m    | Bit scan forward | 1-4 cycles |
| **BSR**  | 0F BD  | Legacy   | All   | r,r/m    | Bit scan reverse | 1-4 cycles |

### B. BMI/BMI2 Instructions (VEX)

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **ANDN** | VEX.LZ.0F38.W0 F2| VEX | 32/64 | r,r,r/m  | Logical AND NOT | 1 cycle |
| **BLSR** | VEX.LZ.0F38.W0 F3/1| VEX | 32/64 | r,r/m | Reset lowest set bit | 1 cycle |
| **BLSMSK**| VEX.LZ.0F38.W0 F3/2| VEX | 32/64 | r,r/m | Get mask to lowest set bit | 1 cycle |
| **BLSI** | VEX.LZ.0F38.W0 F3/3| VEX | 32/64 | r,r/m | Isolate lowest set bit | 1 cycle |
| **BZHI** | VEX.LZ.0F38.W0 F5| VEX | 32/64 | r,r/m,r | Zero high bits | 1 cycle |
| **PEXT** | VEX.LZ.F3.0F38.W0 F5| VEX | 32/64 | r,r,r/m | Parallel extract | 3 cycles |
| **PDEP** | VEX.LZ.F2.0F38.W0 F5| VEX | 32/64 | r,r,r/m | Parallel deposit | 3 cycles |

---

## VIII. SIMD INSTRUCTIONS

### A. MMX (Legacy 64-bit)

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **MOVQ** | 0F 6F  | Legacy   | All   | mm,mm/m64| Move quadword | 1 cycle |
| **PADDW**| 0F FD  | Legacy   | All   | mm,mm/m64| Packed add words | 1 cycle |
| **PMULLW**| 0F D5 | Legacy   | All   | mm,mm/m64| Packed multiply low | 3 cycles |
| **EMMS** | 0F 77  | Legacy   | All   | -        | Empty MMX state | 6 cycles |

### B. SSE (128-bit Scalar/Packed)

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **MOVAPS**| 0F 28 | Legacy   | All   | xmm,xmm/m128| Move aligned packed single | 1 cycle |
| **MOVUPS**| 0F 10 | Legacy   | All   | xmm,xmm/m128| Move unaligned packed single | 1 cycle |
| **ADDPS** | 0F 58 | Legacy   | All   | xmm,xmm/m128| Add packed single | 3 cycles |
| **MULPS** | 0F 59 | Legacy   | All   | xmm,xmm/m128| Multiply packed single | 4 cycles |
| **CMPPS** | 0F C2 | Legacy   | All   | xmm,xmm/m128,imm8| Compare packed single | 3 cycles |

### C. AVX (VEX-encoded 256-bit)

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **VADDPS**| VEX.256.0F.WIG 58| VEX | 32/64 | ymm,ymm,ymm/m256| Add packed single | 3 cycles |
| **VMULPS**| VEX.256.0F.WIG 59| VEX | 32/64 | ymm,ymm,ymm/m256| Multiply packed single | 4 cycles |
| **VBROADCASTSS**| VEX.256.66.0F38.W0 18| VEX | 32/64 | ymm,m32 | Broadcast scalar single | 1 cycle |
| **VPERM2F128**| VEX.256.66.0F3A.W0 06| VEX | 32/64 | ymm,ymm,ymm/m256,imm8| Permute 128-bit lanes | 3 cycles |

### D. AVX-512 (EVEX-encoded 512-bit)

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **VADDPS**| EVEX.512.0F.W0 58| EVEX | 64 | zmm{k},zmm,zmm/m512/b32| Add packed single | 4 cycles |
| **VFMADD213PS**| EVEX.512.66.0F38.W0 A8| EVEX | 64 | zmm{k},zmm,zmm/m512/b32| Fused multiply-add | 4 cycles |
| **VGATHERDPS**| EVEX.512.66.0F38.W0 92| EVEX | 64 | zmm{k},vm32z | Gather packed single | 10+ cycles |

---

## IX. SYSTEM INSTRUCTIONS

### A. Privilege/Mode Control

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **CLI**  | FA     | Legacy   | All   | -        | Clear interrupt flag | 7 cycles |
| **STI**  | FB     | Legacy   | All   | -        | Set interrupt flag | 7 cycles |
| **HLT**  | F4     | Legacy   | All   | -        | Halt processor | - |
| **IRET** | CF     | Legacy   | All   | -        | Interrupt return | 10+ cycles |
| **SYSCALL**| 0F 05| Legacy   | 64    | -        | System call (64-bit) | 20+ cycles |
| **SYSENTER**| 0F 34| Legacy   | 32   | -        | System call (32-bit) | 20+ cycles |

### B. Memory Management

| Mnemonic | Opcode | Encoding | Modes | Operands | Description | Latency |
|----------|---------|----------|-------|----------|-------------|---------|
| **LGDT** | 0F 01/2| Legacy   | All   | m        | Load global descriptor table | 10+ cycles |
| **LIDT** | 0F 01/3| Legacy   | All   | m        | Load interrupt descriptor table | 10+ cycles |
| **INVLPG**| 0F 01/7| Legacy   | All   | m        | Invalidate page in TLB | 100+ cycles |
| **MOV**  | 0F 20  | Legacy   | All   | r,CRn    | Move from control register | 10+ cycles |
| **MOV**  | 0F 22  | Legacy   | All   | CRn,r    | Move to control register | 20+ cycles |

---

## X. ENCODING FAMILY SUMMARY

### Legacy Encoding (8086-compatible)
- **Prefix:** None, REP, LOCK, segment override
- **Opcode:** 1-2 bytes  
- **ModR/M:** Optional addressing mode byte
- **SIB:** Optional scale-index-base byte
- **Displacement:** 0/1/2/4 bytes
- **Immediate:** 0/1/2/4 bytes

### REX Prefix (64-bit mode)
- **Format:** 0100WRXB
- **W:** 64-bit operand size
- **R:** Extension of ModR/M.reg field  
- **X:** Extension of SIB.index field
- **B:** Extension of ModR/M.r/m or SIB.base field

### VEX Prefix (AVX)
- **2-byte:** C5 RvvvvLpp
- **3-byte:** C4 RXBmmmmm WvvvvLpp
- **mmmmm:** Escape/opcode map
- **vvvv:** Source register (inverted)
- **L:** Vector length (0=128-bit, 1=256-bit)
- **pp:** Mandatory prefix encoding

### EVEX Prefix (AVX-512)
- **Format:** 62 RXBRmmm WvvvvLLpp KzB
- **LL:** Vector length (00=128, 01=256, 10=512)
- **K:** Opmask register selection
- **z:** Zeroing/merging control
- **B:** Broadcast/rounding control

---

## XI. REGISTER ENCODING REFERENCE

### General Purpose Registers
| 16-bit | 32-bit | 64-bit | REX.B=0 | REX.B=1 |
|--------|--------|--------|---------|---------|
| AX     | EAX    | RAX    | 000     | 1000    |
| CX     | ECX    | RCX    | 001     | 1001    |
| DX     | EDX    | RDX    | 010     | 1010    |
| BX     | EBX    | RBX    | 011     | 1011    |
| SP     | ESP    | RSP    | 100     | 1100    |
| BP     | EBP    | RBP    | 101     | 1101    |
| SI     | ESI    | RSI    | 110     | 1110    |
| DI     | EDI    | RDI    | 111     | 1111    |
| -      | -      | R8     | -       | 1000 (new)|
| -      | -      | R9-R15 | -       | 1001-1111|

### SIMD Registers
| Legacy | AVX    | AVX-512 | Encoding |
|--------|--------|---------|----------|
| XMM0   | YMM0   | ZMM0    | 0000     |
| XMM1   | YMM1   | ZMM1    | 0001     |
| ...    | ...    | ...     | ...      |
| XMM15  | YMM15  | ZMM15   | 1111     |
| -      | -      | ZMM16   | 10000 (EVEX)|
| -      | -      | ZMM31   | 11111 (EVEX)|

---

This Phase I matrix provides the foundation for complete instruction encoding analysis. Would you like me to continue with Phase II (detailed microarchitecture timing) or Phase III (cross-dialect syntax translation tables)?
