/*
 * ARM64 (AArch64) specific runtime support for BCPL
 * Optimized for ARMv8-A and later architectures
 */

#include "bcpl_runtime.h"
#include <stdint.h>
#include <sys/mman.h>

#ifdef BCPL_ARM64

// ARM64-specific word size and alignment
#define BCPL_ARM64_WORD_SIZE 8
#define BCPL_ARM64_ALIGNMENT 8

// ARM64 calling convention helpers
extern void bcpl_arm64_call_helper(void);

// ARM64-specific memory management
void *bcpl_arm64_alloc_executable(size_t size) {
  void *mem = mmap(NULL, size, PROT_READ | PROT_WRITE | PROT_EXEC,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (mem == MAP_FAILED) {
    return NULL;
  }
  return mem;
}

// ARM64 NEON optimized memory operations
void bcpl_arm64_memcpy_neon(void *dst, const void *src, size_t len) {
  // Use NEON instructions for large copies
  if (len >= 64) {
    __asm__ volatile("1:\n\t"
                     "ldp q0, q1, [%1], #32\n\t"
                     "ldp q2, q3, [%1], #32\n\t"
                     "stp q0, q1, [%0], #32\n\t"
                     "stp q2, q3, [%0], #32\n\t"
                     "subs %2, %2, #64\n\t"
                     "bge 1b\n\t"
                     : "+r"(dst), "+r"(src), "+r"(len)
                     :
                     : "memory", "v0", "v1", "v2", "v3");
  }

  // Handle remaining bytes
  char *d = (char *)dst;
  char *s = (char *)src;
  while (len-- > 0) {
    *d++ = *s++;
  }
}

// ARM64 cache management
void bcpl_arm64_flush_icache(void *addr, size_t len) {
  uintptr_t start = (uintptr_t)addr;
  uintptr_t end = start + len;

  // Clean data cache and invalidate instruction cache
  for (uintptr_t p = start; p < end; p += 64) {
    __asm__ volatile("dc cvau, %0" : : "r"(p) : "memory");
  }
  __asm__ volatile("dsb ish" : : : "memory");

  for (uintptr_t p = start; p < end; p += 64) {
    __asm__ volatile("ic ivau, %0" : : "r"(p) : "memory");
  }
  __asm__ volatile("dsb ish; isb" : : : "memory");
}

// ARM64 atomic operations
uint64_t bcpl_arm64_atomic_add(volatile uint64_t *ptr, uint64_t value) {
  uint64_t result;
  __asm__ volatile("ldaxr %0, [%2]\n\t"
                   "add %0, %0, %1\n\t"
                   "stlxr w3, %0, [%2]\n\t"
                   "cbnz w3, .-12"
                   : "=&r"(result)
                   : "r"(value), "r"(ptr)
                   : "w3", "memory");
  return result;
}

// ARM64 performance counters (if available)
uint64_t bcpl_arm64_get_cycle_count(void) {
  uint64_t cycles;
  __asm__ volatile("mrs %0, cntvct_el0" : "=r"(cycles));
  return cycles;
}

// ARM64 stack pointer utilities
void *bcpl_arm64_get_stack_pointer(void) {
  void *sp;
  __asm__ volatile("mov %0, sp" : "=r"(sp));
  return sp;
}

// ARM64 function call optimization
typedef struct {
  uint64_t x0, x1, x2, x3, x4, x5, x6, x7;
  double d0, d1, d2, d3, d4, d5, d6, d7;
} bcpl_arm64_regs_t;

// ARM64 BCPL function wrapper
uint64_t bcpl_arm64_call_function(void *func, bcpl_arm64_regs_t *regs) {
  uint64_t result;
  __asm__ volatile("ldp x0, x1, [%1, #0]\n\t"
                   "ldp x2, x3, [%1, #16]\n\t"
                   "ldp x4, x5, [%1, #32]\n\t"
                   "ldp x6, x7, [%1, #48]\n\t"
                   "ldr d0, [%1, #64]\n\t"
                   "ldr d1, [%1, #72]\n\t"
                   "ldr d2, [%1, #80]\n\t"
                   "ldr d3, [%1, #88]\n\t"
                   "ldr d4, [%1, #96]\n\t"
                   "ldr d5, [%1, #104]\n\t"
                   "ldr d6, [%1, #112]\n\t"
                   "ldr d7, [%1, #120]\n\t"
                   "blr %2\n\t"
                   "mov %0, x0"
                   : "=r"(result)
                   : "r"(regs), "r"(func)
                   : "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "d0", "d1",
                     "d2", "d3", "d4", "d5", "d6", "d7", "lr", "memory");
  return result;
}

// ARM64 initialization
void bcpl_arm64_init(void) {
  // Check for ARM64 features
  uint64_t midr;
  __asm__ volatile("mrs %0, midr_el1" : "=r"(midr));

  // Enable performance monitoring if available
  uint64_t pmcr;
  __asm__ volatile("mrs %0, pmcr_el0" : "=r"(pmcr));
  if (pmcr & (1 << 11)) { // N field indicates number of counters
    __asm__ volatile("msr pmcr_el0, %0" : : "r"(pmcr | 1));
  }
}

#endif // BCPL_ARM64
