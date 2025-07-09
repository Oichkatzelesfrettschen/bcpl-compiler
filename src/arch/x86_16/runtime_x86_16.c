/*
 * x86_16 (8086/80286) specific runtime support for BCPL
 * Optimized for 16-bit x86 architecture - legacy support
 */

#include "bcpl_runtime.h"
#include <stdint.h>

#ifdef BCPL_X86_16

// x86_16-specific word size and alignment
#define BCPL_X86_16_WORD_SIZE 2
#define BCPL_X86_16_ALIGNMENT 2

// x86_16 doesn't have sophisticated features like modern processors
static uint16_t x86_16_features = 0;
#define X86_16_FEAT_80286 (1 << 0)
#define X86_16_FEAT_80386 (1 << 1)

// x86_16 memory management (very limited)
void *bcpl_x86_16_alloc_memory(size_t size) {
  // In real 16-bit mode, we'd use DOS/BIOS calls
  // This is a placeholder for hosted environments
  return malloc(size);
}

// Basic memory operations (no SIMD in 16-bit mode)
void bcpl_x86_16_memcpy(void *dst, const void *src, size_t len) {
  // Use string instructions for efficiency
  __asm__ volatile("cld\n\t"
                   "rep movsb"
                   : "=D"(dst), "=S"(src), "=c"(len)
                   : "0"(dst), "1"(src), "2"(len)
                   : "memory");
}

// x86_16 doesn't have atomic operations in the modern sense
uint16_t bcpl_x86_16_atomic_add(volatile uint16_t *ptr, uint16_t value) {
  // Disable interrupts for atomicity (not portable)
  uint16_t flags;
  __asm__ volatile("pushf; cli; popw %0" : "=r"(flags));

  uint16_t old_val = *ptr;
  *ptr += value;

  // Restore interrupt flag
  __asm__ volatile("pushw %0; popf" : : "r"(flags));

  return old_val;
}

// x86_16 has no performance counters
uint32_t bcpl_x86_16_get_tick_count(void) {
  // Use BIOS timer tick (int 1Ah)
  uint32_t ticks;
  __asm__ volatile("movb $0x00, %%ah\n\t"
                   "int $0x1a"
                   : "=d"(ticks)
                   :
                   : "ah", "al", "cx");
  return ticks;
}

// x86_16 stack utilities
void *bcpl_x86_16_get_stack_pointer(void) {
  void *sp;
  __asm__ volatile("movw %%sp, %0" : "=r"(sp));
  return sp;
}

// x86_16 calling convention (Pascal/cdecl for 16-bit)
typedef struct {
  uint16_t ax, bx, cx, dx;
  uint16_t si, di;
} bcpl_x86_16_regs_t;

// x86_16 BCPL function wrapper
uint16_t bcpl_x86_16_call_function(void *func, bcpl_x86_16_regs_t *regs) {
  uint16_t result;
  __asm__ volatile("movw 0(%1), %%ax\n\t"
                   "movw 2(%1), %%bx\n\t"
                   "movw 4(%1), %%cx\n\t"
                   "movw 6(%1), %%dx\n\t"
                   "movw 8(%1), %%si\n\t"
                   "movw 10(%1), %%di\n\t"
                   "call *%2\n\t"
                   "movw %%ax, %0"
                   : "=r"(result)
                   : "r"(regs), "r"(func)
                   : "ax", "bx", "cx", "dx", "si", "di", "memory");
  return result;
}

// x86_16 feature detection (very basic)
void bcpl_x86_16_detect_features(void) {
  // Test for 80286 vs 8086/8088
  uint16_t flags;
  __asm__ volatile("pushf\n\t"
                   "popw %%ax\n\t"
                   "movw %%ax, %%bx\n\t"
                   "andw $0x0fff, %%ax\n\t"
                   "pushw %%ax\n\t"
                   "popf\n\t"
                   "pushf\n\t"
                   "popw %%ax\n\t"
                   "andw $0xf000, %%ax\n\t"
                   "cmpw $0xf000, %%ax\n\t"
                   "je 1f\n\t"
                   "movw $1, %0\n\t"
                   "jmp 2f\n\t"
                   "1: movw $0, %0\n\t"
                   "2: pushw %%bx\n\t"
                   "popf"
                   : "=r"(flags)
                   :
                   : "ax", "bx");

  if (flags) {
    x86_16_features |= X86_16_FEAT_80286;
  }
}

// x86_16 initialization
void bcpl_x86_16_init(void) {
  bcpl_x86_16_detect_features();

  // Set up segment registers for large model if needed
  // (This would be more complex in real mode)
}

// x86_16 I/O operations (direct port access)
uint8_t bcpl_x86_16_inb(uint16_t port) {
  uint8_t value;
  __asm__ volatile("inb %1, %0" : "=a"(value) : "Nd"(port));
  return value;
}

void bcpl_x86_16_outb(uint16_t port, uint8_t value) {
  __asm__ volatile("outb %0, %1" : : "a"(value), "Nd"(port));
}

uint16_t bcpl_x86_16_inw(uint16_t port) {
  uint16_t value;
  __asm__ volatile("inw %1, %0" : "=a"(value) : "Nd"(port));
  return value;
}

void bcpl_x86_16_outw(uint16_t port, uint16_t value) {
  __asm__ volatile("outw %0, %1" : : "a"(value), "Nd"(port));
}

// x86_16 interrupt handling
void bcpl_x86_16_disable_interrupts(void) {
  __asm__ volatile("cli" : : : "memory");
}

void bcpl_x86_16_enable_interrupts(void) {
  __asm__ volatile("sti" : : : "memory");
}

// x86_16 segment operations
uint16_t bcpl_x86_16_get_cs(void) {
  uint16_t cs;
  __asm__ volatile("movw %%cs, %0" : "=r"(cs));
  return cs;
}

uint16_t bcpl_x86_16_get_ds(void) {
  uint16_t ds;
  __asm__ volatile("movw %%ds, %0" : "=r"(ds));
  return ds;
}

uint16_t bcpl_x86_16_get_es(void) {
  uint16_t es;
  __asm__ volatile("movw %%es, %0" : "=r"(es));
  return es;
}

uint16_t bcpl_x86_16_get_ss(void) {
  uint16_t ss;
  __asm__ volatile("movw %%ss, %0" : "=r"(ss));
  return ss;
}

// Far pointer operations for segmented memory model
typedef struct {
  uint16_t offset;
  uint16_t segment;
} bcpl_far_ptr_t;

void *bcpl_x86_16_make_far_ptr(uint16_t segment, uint16_t offset) {
  static bcpl_far_ptr_t ptr;
  ptr.segment = segment;
  ptr.offset = offset;
  return &ptr;
}

// x86_16 string operations
void bcpl_x86_16_rep_stosb(void *dst, uint8_t value, size_t count) {
  __asm__ volatile("cld\n\t"
                   "rep stosb"
                   : "=D"(dst), "=c"(count)
                   : "0"(dst), "1"(count), "a"(value)
                   : "memory");
}

void bcpl_x86_16_rep_stosw(void *dst, uint16_t value, size_t count) {
  __asm__ volatile("cld\n\t"
                   "rep stosw"
                   : "=D"(dst), "=c"(count)
                   : "0"(dst), "1"(count), "a"(value)
                   : "memory");
}

#endif // BCPL_X86_16
