/*
 * x86_64 (AMD64) specific runtime support for BCPL
 * Optimized for x86-64 architecture with SSE/AVX support
 */

#include "../runtime/bcpl_runtime.h"
#include <cpuid.h>
#include <stdint.h>
#include <sys/mman.h>

#ifdef BCPL_X86_64

// x86_64-specific word size and alignment
#define BCPL_X86_64_WORD_SIZE 8
#define BCPL_X86_64_ALIGNMENT 16 // SSE requires 16-byte alignment

// x86_64 feature detection
static uint32_t x86_64_features = 0;
#define X86_64_FEAT_SSE2 (1 << 0)
#define X86_64_FEAT_SSE3 (1 << 1)
#define X86_64_FEAT_SSE4_1 (1 << 2)
#define X86_64_FEAT_SSE4_2 (1 << 3)
#define X86_64_FEAT_AVX (1 << 4)
#define X86_64_FEAT_AVX2 (1 << 5)

// x86_64-specific memory management
void *bcpl_x86_64_alloc_executable(size_t size) {
  void *mem = mmap(NULL, size, PROT_READ | PROT_WRITE | PROT_EXEC,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (mem == MAP_FAILED) {
    return NULL;
  }
  return mem;
}

// SSE2 optimized memory operations
void bcpl_x86_64_memcpy_sse2(void *dst, const void *src, size_t len) {
  if (!(x86_64_features & X86_64_FEAT_SSE2) || len < 64) {
    // Fallback to standard memcpy
    __builtin_memcpy(dst, src, len);
    return;
  }

  __asm__ volatile("1:\n\t"
                   "movdqa (%1), %%xmm0\n\t"
                   "movdqa 16(%1), %%xmm1\n\t"
                   "movdqa 32(%1), %%xmm2\n\t"
                   "movdqa 48(%1), %%xmm3\n\t"
                   "movdqa %%xmm0, (%0)\n\t"
                   "movdqa %%xmm1, 16(%0)\n\t"
                   "movdqa %%xmm2, 32(%0)\n\t"
                   "movdqa %%xmm3, 48(%0)\n\t"
                   "add $64, %0\n\t"
                   "add $64, %1\n\t"
                   "sub $64, %2\n\t"
                   "jge 1b"
                   : "+r"(dst), "+r"(src), "+r"(len)
                   :
                   : "memory", "xmm0", "xmm1", "xmm2", "xmm3");
}

// x86_64 cache management
void bcpl_x86_64_flush_cache(void *addr, size_t len) {
  // x86_64 has coherent caches, but we still need to serialize
  __asm__ volatile("mfence" : : : "memory");
}

// x86_64 atomic operations using lock prefix
uint64_t bcpl_x86_64_atomic_add(volatile uint64_t *ptr, uint64_t value) {
  uint64_t result = value;
  __asm__ volatile("lock xaddq %0, %1" : "+r"(result), "+m"(*ptr) : : "memory");
  return result + value;
}

// x86_64 performance counters
uint64_t bcpl_x86_64_get_cycle_count(void) {
  uint32_t low, high;
  __asm__ volatile("rdtsc" : "=a"(low), "=d"(high));
  return ((uint64_t)high << 32) | low;
}

// x86_64 stack pointer utilities
void *bcpl_x86_64_get_stack_pointer(void) {
  void *sp;
  __asm__ volatile("movq %%rsp, %0" : "=r"(sp));
  return sp;
}

// x86_64 calling convention (System V AMD64 ABI)
typedef struct {
  uint64_t rdi, rsi, rdx, rcx, r8, r9;
  double xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7;
} bcpl_x86_64_regs_t;

// x86_64 BCPL function wrapper
uint64_t bcpl_x86_64_call_function(void *func, bcpl_x86_64_regs_t *regs) {
  uint64_t result;
  __asm__ volatile("movq 0(%1), %%rdi\n\t"
                   "movq 8(%1), %%rsi\n\t"
                   "movq 16(%1), %%rdx\n\t"
                   "movq 24(%1), %%rcx\n\t"
                   "movq 32(%1), %%r8\n\t"
                   "movq 40(%1), %%r9\n\t"
                   "movsd 48(%1), %%xmm0\n\t"
                   "movsd 56(%1), %%xmm1\n\t"
                   "movsd 64(%1), %%xmm2\n\t"
                   "movsd 72(%1), %%xmm3\n\t"
                   "movsd 80(%1), %%xmm4\n\t"
                   "movsd 88(%1), %%xmm5\n\t"
                   "movsd 96(%1), %%xmm6\n\t"
                   "movsd 104(%1), %%xmm7\n\t"
                   "callq *%2\n\t"
                   "movq %%rax, %0"
                   : "=r"(result)
                   : "r"(regs), "r"(func)
                   : "rdi", "rsi", "rdx", "rcx", "r8", "r9", "rax", "xmm0",
                     "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7",
                     "memory");
  return result;
}

// x86_64 feature detection
void bcpl_x86_64_detect_features(void) {
  uint32_t eax, ebx, ecx, edx;

  // Check for CPUID support
  if (__get_cpuid(1, &eax, &ebx, &ecx, &edx)) {
    if (edx & (1 << 26))
      x86_64_features |= X86_64_FEAT_SSE2;
    if (ecx & (1 << 0))
      x86_64_features |= X86_64_FEAT_SSE3;
    if (ecx & (1 << 19))
      x86_64_features |= X86_64_FEAT_SSE4_1;
    if (ecx & (1 << 20))
      x86_64_features |= X86_64_FEAT_SSE4_2;
    if (ecx & (1 << 28))
      x86_64_features |= X86_64_FEAT_AVX;
  }

  // Check for AVX2
  if (__get_cpuid_count(7, 0, &eax, &ebx, &ecx, &edx)) {
    if (ebx & (1 << 5))
      x86_64_features |= X86_64_FEAT_AVX2;
  }
}

// x86_64 initialization
void bcpl_x86_64_init(void) {
  bcpl_x86_64_detect_features();

  // Enable OSFXSR for SSE/AVX support (usually already enabled)
  uint64_t cr4;
  __asm__ volatile("movq %%cr4, %0" : "=r"(cr4));
  if (!(cr4 & (1 << 9))) { // OSFXSR bit
    cr4 |= (1 << 9);
    __asm__ volatile("movq %0, %%cr4" : : "r"(cr4));
  }
}

// x86_64 specific optimizations
void bcpl_x86_64_prefetch(const void *addr) { __builtin_prefetch(addr, 0, 3); }

// x86_64 memory barriers
void bcpl_x86_64_memory_barrier(void) {
  __asm__ volatile("mfence" : : : "memory");
}

void bcpl_x86_64_load_barrier(void) {
  __asm__ volatile("lfence" : : : "memory");
}

void bcpl_x86_64_store_barrier(void) {
  __asm__ volatile("sfence" : : : "memory");
}

#endif // BCPL_X86_64
