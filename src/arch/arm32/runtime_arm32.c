/*
 * ARM32 specific runtime support for BCPL
 * Optimized for ARMv7-A and ARMv8-A (32-bit mode)
 */

#include "../runtime/bcpl_runtime.h"
#include <stdint.h>
#include <sys/mman.h>

#ifdef BCPL_ARM32

// ARM32-specific word size and alignment
#define BCPL_ARM32_WORD_SIZE 4
#define BCPL_ARM32_ALIGNMENT 8 // NEON requires 8-byte alignment

// ARM32 feature detection
static uint32_t arm32_features = 0;
#define ARM32_FEAT_NEON (1 << 0)
#define ARM32_FEAT_VFP (1 << 1)
#define ARM32_FEAT_THUMB2 (1 << 2)

// ARM32-specific memory management
void *bcpl_arm32_alloc_executable(size_t size) {
  void *mem = mmap(NULL, size, PROT_READ | PROT_WRITE | PROT_EXEC,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (mem == MAP_FAILED) {
    return NULL;
  }
  return mem;
}

// NEON optimized memory operations
void bcpl_arm32_memcpy_neon(void *dst, const void *src, size_t len) {
  if (!(arm32_features & ARM32_FEAT_NEON) || len < 32) {
    // Fallback to standard memcpy
    __builtin_memcpy(dst, src, len);
    return;
  }

  __asm__ volatile("1:\n\t"
                   "vld1.8 {q0, q1}, [%1]!\n\t"
                   "vst1.8 {q0, q1}, [%0]!\n\t"
                   "subs %2, %2, #32\n\t"
                   "bge 1b"
                   : "+r"(dst), "+r"(src), "+r"(len)
                   :
                   : "memory", "q0", "q1");
}

// ARM32 cache management
void bcpl_arm32_flush_icache(void *addr, size_t len) {
  uintptr_t start = (uintptr_t)addr;
  uintptr_t end = start + len;

  // Clean data cache
  for (uintptr_t p = start; p < end; p += 32) {
    __asm__ volatile("mcr p15, 0, %0, c7, c10, 1" : : "r"(p) : "memory");
  }

  // Data synchronization barrier
  __asm__ volatile("mcr p15, 0, %0, c7, c10, 4" : : "r"(0) : "memory");

  // Invalidate instruction cache
  for (uintptr_t p = start; p < end; p += 32) {
    __asm__ volatile("mcr p15, 0, %0, c7, c5, 1" : : "r"(p) : "memory");
  }

  // Instruction synchronization barrier
  __asm__ volatile("mcr p15, 0, %0, c7, c5, 4" : : "r"(0) : "memory");
}

// ARM32 atomic operations
uint32_t bcpl_arm32_atomic_add(volatile uint32_t *ptr, uint32_t value) {
  uint32_t result, tmp;
  __asm__ volatile("1:\n\t"
                   "ldrex %0, [%3]\n\t"
                   "add %1, %0, %2\n\t"
                   "strex %0, %1, [%3]\n\t"
                   "cmp %0, #0\n\t"
                   "bne 1b"
                   : "=&r"(tmp), "=&r"(result)
                   : "r"(value), "r"(ptr)
                   : "memory");
  return result;
}

// ARM32 performance counters (if available)
uint32_t bcpl_arm32_get_cycle_count(void) {
  uint32_t cycles;
  __asm__ volatile("mrc p15, 0, %0, c9, c13, 0" : "=r"(cycles));
  return cycles;
}

// ARM32 stack pointer utilities
void *bcpl_arm32_get_stack_pointer(void) {
  void *sp;
  __asm__ volatile("mov %0, sp" : "=r"(sp));
  return sp;
}

// ARM32 calling convention (AAPCS)
typedef struct {
  uint32_t r0, r1, r2, r3;
  float s0, s1, s2, s3, s4, s5, s6, s7;
  float s8, s9, s10, s11, s12, s13, s14, s15;
} bcpl_arm32_regs_t;

// ARM32 BCPL function wrapper
uint32_t bcpl_arm32_call_function(void *func, bcpl_arm32_regs_t *regs) {
  uint32_t result;
  __asm__ volatile("ldm %1, {r0-r3}\n\t"
                   "add r4, %1, #16\n\t"
                   "vldm r4, {s0-s15}\n\t"
                   "blx %2\n\t"
                   "mov %0, r0"
                   : "=r"(result)
                   : "r"(regs), "r"(func)
                   : "r0", "r1", "r2", "r3", "r4", "lr", "s0", "s1", "s2", "s3",
                     "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11", "s12",
                     "s13", "s14", "s15", "memory");
  return result;
}

// ARM32 feature detection
void bcpl_arm32_detect_features(void) {
  uint32_t fpsid, mvfr0;

  // Check for VFP support
  __asm__ volatile("mrc p10, 7, %0, c0, c0, 0" : "=r"(fpsid));
  if ((fpsid & 0xFF000000) != 0) {
    arm32_features |= ARM32_FEAT_VFP;
  }

  // Check for NEON support
  __asm__ volatile("mrc p10, 7, %0, c7, c0, 0" : "=r"(mvfr0));
  if ((mvfr0 & 0x000000F0) == 0x00000010) {
    arm32_features |= ARM32_FEAT_NEON;
  }

  // Check for Thumb-2 support (present in ARMv7 and later)
  uint32_t id_isar0;
  __asm__ volatile("mrc p15, 0, %0, c0, c2, 0" : "=r"(id_isar0));
  if ((id_isar0 & 0x0F000000) >= 0x02000000) {
    arm32_features |= ARM32_FEAT_THUMB2;
  }
}

// ARM32 initialization
void bcpl_arm32_init(void) {
  bcpl_arm32_detect_features();

  // Enable NEON/VFP if available
  if (arm32_features & (ARM32_FEAT_NEON | ARM32_FEAT_VFP)) {
    uint32_t fpexc;
    __asm__ volatile("mrc p10, 7, %0, c8, c0, 0" : "=r"(fpexc));
    fpexc |= (1 << 30); // Enable VFP/NEON
    __asm__ volatile("mcr p10, 7, %0, c8, c0, 0" : : "r"(fpexc));
  }

  // Enable performance monitoring if available
  uint32_t pmcr;
  __asm__ volatile("mrc p15, 0, %0, c9, c12, 0" : "=r"(pmcr));
  if (pmcr & (0x1F << 11)) { // N field indicates number of counters
    pmcr |= 1;               // Enable
    __asm__ volatile("mcr p15, 0, %0, c9, c12, 0" : : "r"(pmcr));
  }
}

// ARM32 specific optimizations
void bcpl_arm32_prefetch(const void *addr) {
  __asm__ volatile("pld [%0]" : : "r"(addr) : "memory");
}

// ARM32 memory barriers
void bcpl_arm32_memory_barrier(void) { __asm__ volatile("dmb" : : : "memory"); }

void bcpl_arm32_sync_barrier(void) { __asm__ volatile("dsb" : : : "memory"); }

void bcpl_arm32_instruction_barrier(void) {
  __asm__ volatile("isb" : : : "memory");
}

#endif // BCPL_ARM32
