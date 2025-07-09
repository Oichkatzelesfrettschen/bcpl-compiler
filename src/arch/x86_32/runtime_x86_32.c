/*
 * x86_32 (i386) specific runtime support for BCPL
 * Optimized for 32-bit x86 architecture
 */

#include "bcpl_runtime.h"
#include <stdint.h>
#include <sys/mman.h>

#ifdef BCPL_X86_32

// x86_32-specific word size and alignment
#define BCPL_X86_32_WORD_SIZE 4
#define BCPL_X86_32_ALIGNMENT 16 // SSE requires 16-byte alignment

// x86_32 feature detection
static uint32_t x86_32_features = 0;
#define X86_32_FEAT_SSE (1 << 0)
#define X86_32_FEAT_SSE2 (1 << 1)
#define X86_32_FEAT_MMX (1 << 2)

// x86_32-specific memory management
void *bcpl_x86_32_alloc_executable(size_t size) {
  void *mem = mmap(NULL, size, PROT_READ | PROT_WRITE | PROT_EXEC,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (mem == MAP_FAILED) {
    return NULL;
  }
  return mem;
}

// SSE optimized memory operations (if available)
void bcpl_x86_32_memcpy_sse(void *dst, const void *src, size_t len) {
  if (!(x86_32_features & X86_32_FEAT_SSE) || len < 64) {
    // Fallback to standard memcpy
    __builtin_memcpy(dst, src, len);
    return;
  }

  __asm__ volatile("1:\n\t"
                   "movaps (%1), %%xmm0\n\t"
                   "movaps 16(%1), %%xmm1\n\t"
                   "movaps 32(%1), %%xmm2\n\t"
                   "movaps 48(%1), %%xmm3\n\t"
                   "movaps %%xmm0, (%0)\n\t"
                   "movaps %%xmm1, 16(%0)\n\t"
                   "movaps %%xmm2, 32(%0)\n\t"
                   "movaps %%xmm3, 48(%0)\n\t"
                   "add $64, %0\n\t"
                   "add $64, %1\n\t"
                   "sub $64, %2\n\t"
                   "jge 1b"
                   : "+r"(dst), "+r"(src), "+r"(len)
                   :
                   : "memory", "xmm0", "xmm1", "xmm2", "xmm3");
}

// x86_32 cache management
void bcpl_x86_32_flush_cache(void *addr, size_t len) {
  // x86 has coherent caches, but we still need to serialize
  __asm__ volatile("mfence" : : : "memory");
}

// x86_32 atomic operations
uint32_t bcpl_x86_32_atomic_add(volatile uint32_t *ptr, uint32_t value) {
  uint32_t result = value;
  __asm__ volatile("lock xaddl %0, %1" : "+r"(result), "+m"(*ptr) : : "memory");
  return result + value;
}

// x86_32 performance counters
uint64_t bcpl_x86_32_get_cycle_count(void) {
  uint32_t low, high;
  __asm__ volatile("rdtsc" : "=a"(low), "=d"(high));
  return ((uint64_t)high << 32) | low;
}

// x86_32 stack pointer utilities
void *bcpl_x86_32_get_stack_pointer(void) {
  void *sp;
  __asm__ volatile("movl %%esp, %0" : "=r"(sp));
  return sp;
}

// x86_32 calling convention (cdecl/stdcall)
typedef struct {
  uint32_t eax, ecx, edx;       // Available for parameters
  float xmm0, xmm1, xmm2, xmm3; // If SSE available
} bcpl_x86_32_regs_t;

// x86_32 BCPL function wrapper
uint32_t bcpl_x86_32_call_function(void *func, bcpl_x86_32_regs_t *regs) {
  uint32_t result;
  __asm__ volatile("movl 0(%1), %%eax\n\t"
                   "movl 4(%1), %%ecx\n\t"
                   "movl 8(%1), %%edx\n\t"
                   "call *%2\n\t"
                   "movl %%eax, %0"
                   : "=r"(result)
                   : "r"(regs), "r"(func)
                   : "eax", "ecx", "edx", "memory");
  return result;
}

// x86_32 feature detection
void bcpl_x86_32_detect_features(void) {
  uint32_t eax, ebx, ecx, edx;

  // Check for CPUID support
  __asm__ volatile("pushfl\n\t"
                   "popl %%eax\n\t"
                   "movl %%eax, %%ecx\n\t"
                   "xorl $0x200000, %%eax\n\t"
                   "pushl %%eax\n\t"
                   "popfl\n\t"
                   "pushfl\n\t"
                   "popl %%eax\n\t"
                   "xorl %%ecx, %%eax\n\t"
                   "andl $0x200000, %%eax"
                   : "=a"(eax)
                   :
                   : "ecx");

  if (eax == 0)
    return; // No CPUID support

  // Get feature flags
  __asm__ volatile("cpuid"
                   : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
                   : "a"(1));

  if (edx & (1 << 23))
    x86_32_features |= X86_32_FEAT_MMX;
  if (edx & (1 << 25))
    x86_32_features |= X86_32_FEAT_SSE;
  if (edx & (1 << 26))
    x86_32_features |= X86_32_FEAT_SSE2;
}

// x86_32 initialization
void bcpl_x86_32_init(void) {
  bcpl_x86_32_detect_features();

  // Enable SSE if available
  if (x86_32_features & X86_32_FEAT_SSE) {
    uint32_t cr4;
    __asm__ volatile("movl %%cr4, %0" : "=r"(cr4));
    if (!(cr4 & (1 << 9))) { // OSFXSR bit
      cr4 |= (1 << 9);
      __asm__ volatile("movl %0, %%cr4" : : "r"(cr4));
    }
  }
}

// x86_32 specific optimizations
void bcpl_x86_32_prefetch(const void *addr) {
  if (x86_32_features & X86_32_FEAT_SSE) {
    __asm__ volatile("prefetcht0 %0" : : "m"(*(const char *)addr));
  }
}

// x86_32 memory barriers
void bcpl_x86_32_memory_barrier(void) {
  if (x86_32_features & X86_32_FEAT_SSE2) {
    __asm__ volatile("mfence" : : : "memory");
  } else {
    __asm__ volatile("lock; addl $0, (%%esp)" : : : "memory");
  }
}

void bcpl_x86_32_load_barrier(void) {
  if (x86_32_features & X86_32_FEAT_SSE2) {
    __asm__ volatile("lfence" : : : "memory");
  } else {
    __asm__ volatile("" : : : "memory");
  }
}

void bcpl_x86_32_store_barrier(void) {
  if (x86_32_features & X86_32_FEAT_SSE) {
    __asm__ volatile("sfence" : : : "memory");
  } else {
    __asm__ volatile("" : : : "memory");
  }
}

#endif // BCPL_X86_32
