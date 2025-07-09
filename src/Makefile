#==============================================================================
#  bcplc/src  ── canonical build rules
#------------------------------------------------------------------------------
#  • BITS ∈ {64,32,16}  (default 64)
#  • CROSS_PREFIX allows GNU cross-toolchains (e.g. i686-linux-gnu-)
#  • Clang required for C23; override via CC=foo
#  • Portable: Linux (GNU as) & macOS (clang as)                        ───────
#==============================================================================

# ── User-tunable front-matter ────────────────────────────────────────────────
PREFIX        ?= /usr/local
BITS          ?= 64                  # 64|32|16
CROSS_PREFIX  ?=
CC            ?= clang               # must support -std=c23

# Extra caller-injected flags are appended here
CFLAGS_EXTRA  ?=

# ── Derived globals ─────────────────────────────────────────────────────────
CFLAGS   := -std=c23 -Wall -Wextra -Wpedantic -g -DBITS=$(BITS) $(CFLAGS_EXTRA)
AS       :=
AFLAGS   :=
LDMODE   :=
TOTAL_G_SPACE_VAL    :=
WORDSIZE_ALIGN_VAL_G :=

# ── Per-BITS tuning ---------------------------------------------------------
ifeq ($(BITS),64)
  TOTAL_G_SPACE_VAL     := $(shell echo $$((400 * 8)))
  WORDSIZE_ALIGN_VAL_G  := 8
  BYTESPERWORD_VAL      := 8
  BITSPERWORD_VAL       := 64
  MAXINT_VAL            := "#X7FFFFFFFFFFFFFFF"
  MININT_VAL            := "#X8000000000000000"
else ifeq ($(BITS),32)
  TOTAL_G_SPACE_VAL     := $(shell echo $$((400 * 4)))
  WORDSIZE_ALIGN_VAL_G  := 4
  BYTESPERWORD_VAL      := 4
  BITSPERWORD_VAL       := 32
  MAXINT_VAL            := "#X7FFFFFFF"
  MININT_VAL            := "#X80000000"
else ifeq ($(BITS),16)
  TOTAL_G_SPACE_VAL     := $(shell echo $$((400 * 2)))
  WORDSIZE_ALIGN_VAL_G  := 2
  BYTESPERWORD_VAL      := 2
  BITSPERWORD_VAL       := 16
  MAXINT_VAL            := "#X7FFF"
  MININT_VAL            := "#X8000"
else
  $(error Unsupported BITS value ‘$(BITS)’. Use 64, 32, or 16.)
endif

# ── Host OS detection for assembler selection --------------------------------
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
  AS      := clang
  ifeq ($(BITS),64)
    AFLAGS := -c -arch arm64   -DBITS=64
    LDMODE :=
  else ifeq ($(BITS),32)
    AFLAGS := -c -arch i386    -DBITS=32
    LDMODE :=
  else
    $(error 16-bit builds are not supported on macOS.)
  endif
else                                # Assume GNU user-space (Linux/BSD/etc.)
  AS := $(CROSS_PREFIX)as
  ifeq ($(BITS),64)
    AFLAGS := --64 --defsym BITS=64
    LDMODE := elf_x86_64
  else ifeq ($(BITS),32)
    AFLAGS := --32 --defsym BITS=32
    LDMODE := elf_i386
  else
    AFLAGS := --16 --defsym BITS=16
    LDMODE := elf_i386
  endif
endif

# Common assembler flag suffixes
AFLAGS += -g --defsym TOTAL_G_SPACE=$(TOTAL_G_SPACE_VAL) \
              --defsym WORDSIZE_ALIGN_VAL=$(WORDSIZE_ALIGN_VAL_G)

# ── Runtime syscall stubs per OS/BITS ---------------------------------------
OS_UNAME := $(shell uname)
ifeq ($(BITS),16)
  SU_SRC   := su16.s
  SYS_SRC  := sys_ia16.s
else
  SU_SRC   := su.s
  ifeq ($(OS_UNAME),Linux)
    SYS_SRC := $(if $(filter 64,$(BITS)),sys_linux_x86_64.s,sys_linux.s)
  else ifeq ($(OS_UNAME),FreeBSD)
    SYS_SRC := sys_freebsd$(if $(filter 64,$(BITS)),_x86_64).s
  else
    $(error Unsupported host ‘$(OS_UNAME)’ for BITS=$(BITS).)
  endif
endif

# ── Optional LLVM back-end ---------------------------------------------------
LLVM_CONFIG ?= llvm-config
HAVE_LLVM   := $(shell command -v $(LLVM_CONFIG) >/dev/null 2>&1 && echo yes)

ifeq ($(HAVE_LLVM),yes)
  LLVM_CFLAGS  := $(shell $(LLVM_CONFIG) --cflags)
  LLVM_LDFLAGS := $(shell $(LLVM_CONFIG) --ldflags --libs core bitwriter native)
  ALL_TARGETS  := cg op llcg st
else
  LLVM_CFLAGS  :=
  LLVM_LDFLAGS :=
  ALL_TARGETS  := cg op st
endif

# ── Automatic libhdr generation --------------------------------------------
libhdr_local: src/LIBHDR.template Makefile
	@echo "Generating src/libhdr for BITS=$(BITS)…"
	@sed -e "s/@@BYTESPERWORD@@/$(BYTESPERWORD_VAL)/g" \
	     -e "s/@@BITSPERWORD@@/$(BITSPERWORD_VAL)/g"   \
	     -e "s/@@MAXINT@@/$(MAXINT_VAL)/g"             \
	     -e "s/@@MININT@@/$(MININT_VAL)/g"             \
	     $< > src/libhdr

# ── Top-level targets --------------------------------------------------------
all: libhdr_local $(ALL_TARGETS)

cg: cg.o oc.o
	$(CROSS_PREFIX)$(CC) $(CFLAGS) -o $@ $^

oc.o cg.o op.o pt.o llcg.o: %.o : %.c
	$(CROSS_PREFIX)$(CC) $(CFLAGS) $(LLVM_CFLAGS) -c $<

op: op.o pt.o
	$(CROSS_PREFIX)$(CC) $(CFLAGS) -o $@ $^

ifeq ($(HAVE_LLVM),yes)
llcg: llcg.o
	$(CROSS_PREFIX)$(CC) $(CFLAGS) $(LLVM_CFLAGS) -o $@ $< $(LLVM_LDFLAGS)
endif

# ── Assembled runtime --------------------------------------------------------
st: su.o st.o blib.o global.o rt.o sys.o
	$(CROSS_PREFIX)ld -m $(LDMODE) -o $@ $^

su.o blib.o global.o rt.o sys.o st.o: %.o : %.s
	$(AS) $(AFLAGS) -o $@ $<

st.s: cg op st.O libhdr_local
	./cg < st.O | ./op > $@

blib.s: cg op blib.O libhdr_local
	./cg < blib.O | ./op > $@

# ── Self-consistency regression checks --------------------------------------
check: blib.O blib.chk st.O st.chk
	cmp blib.O blib.chk
	cmp st.O   st.chk

blib.chk st.chk: %.chk : %.O
	cp $< $@

# ── Install -----------------------------------------------------------------
install: bcplc bcplc.1 st cg op $(if $(HAVE_LLVM),llcg) \
         src/LIBHDR.template su.o blib.o global.o rt.o sys.o
	@echo "→ Installing to $(PREFIX)…"
	install -d $(PREFIX)/{bin,lib/bcplc,man/man1}
	install -m 755 bcplc                $(PREFIX)/bin
	install -m 644 bcplc.1              $(PREFIX)/man/man1
	install -m 555 st cg op             $(PREFIX)/lib/bcplc
ifneq ($(HAVE_LLVM),)
	install -m 555 llcg                $(PREFIX)/lib/bcplc
endif
	@echo "→ Generating LIBHDR for install (BITS=$(BITS))"
	@sed -e "s/@@BYTESPERWORD@@/$(BYTESPERWORD_VAL)/g" \
	     -e "s/@@BITSPERWORD@@/$(BITSPERWORD_VAL)/g"   \
	     -e "s/@@MAXINT@@/$(MAXINT_VAL)/g"             \
	     -e "s/@@MININT@@/$(MININT_VAL)/g"             \
	     src/LIBHDR.template > $(PREFIX)/lib/bcplc/LIBHDR
	@chmod 644 $(PREFIX)/lib/bcplc/LIBHDR
	ln -sf LIBHDR $(PREFIX)/lib/bcplc/libhdr
	install -m 444 su.o        $(PREFIX)/lib/bcplc/su$(BITS).o
	install -m 444 sys.o       $(PREFIX)/lib/bcplc/sys$(BITS).o
	install -m 444 blib.o global.o rt.o $(PREFIX)/lib/bcplc

# ── Hygiene -----------------------------------------------------------------
clean:
	rm -f cg oc op llcg st *.o *.s blib.chk st.chk src/libhdr
.PHONY: all libhdr_local install clean check
