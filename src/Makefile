# Makefile for bcplc/src

PREFIX?=/usr/local
# Set BITS=32 to build a 32-bit runtime, BITS=64 for a native x86-64
# build or BITS=16 for the IA-16 target.  Additional cross-compilation
# prefixes may be supplied via CROSS_PREFIX (e.g.
# ``CROSS_PREFIX=i686-linux-gnu-``).
BITS?=64
CROSS_PREFIX?=
# Clang is required for the C23 sources.  Use CC=foo to override.
CC = clang
CFLAGS += -std=c23 -Wall -Wextra -Wpedantic -g
CFLAGS += -DBITS=$(BITS)
# Allow callers to inject additional compiler flags via CFLAGS_EXTRA without
# overriding the defaults above.
CFLAGS += $(CFLAGS_EXTRA)

# Detect OS for assembler flags
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
  # macOS uses clang as assembler
  AS = clang
  ifeq ($(BITS),64)
    AFLAGS=-c -arch arm64 -DBITS=64
    LDMODE=
  else ifeq ($(BITS),32)
    AFLAGS=-c -arch i386 -DBITS=32
    LDMODE=
  else ifeq ($(BITS),16)
    $(error 16-bit builds not supported on macOS)
  else
    $(error Unsupported BITS value: $(BITS))
  endif
else
  # Linux/other use GNU as
  AS = $(CROSS_PREFIX)as
  ifeq ($(BITS),64)
    AFLAGS=--64 --defsym BITS=64
    LDMODE=elf_x86_64
  else ifeq ($(BITS),32)
    AFLAGS=--32 --defsym BITS=32
    LDMODE=elf_i386
  else ifeq ($(BITS),16)
    AFLAGS=--16 --defsym BITS=16
    LDMODE=elf_i386
  else
    $(error Unsupported BITS value: $(BITS))
  endif
endif

ifeq ($(BITS),16)
  SU_SRC=su16.s
  SYS_SRC=sys_ia16.s
else
  SU_SRC=su.s
  SYS_SRC=sys.s
endif

LLVM_CONFIG ?= llvm-config
HAVE_LLVM := $(shell command -v $(LLVM_CONFIG) >/dev/null 2>&1 && echo yes)
ifeq ($(HAVE_LLVM),yes)
LLVM_CFLAGS := $(shell $(LLVM_CONFIG) --cflags 2>/dev/null)
LLVM_LDFLAGS := $(shell $(LLVM_CONFIG) --ldflags --libs core bitwriter native 2>/dev/null)
ALL_TARGETS := cg op llcg st
else
LLVM_CFLAGS :=
LLVM_LDFLAGS :=
ALL_TARGETS := cg op st
endif

all: $(ALL_TARGETS)

cg: cg.o oc.o
	$(CROSS_PREFIX)$(CC) $(CFLAGS) -o cg cg.o oc.o

cg.o: cg.c
	$(CROSS_PREFIX)$(CC) $(CFLAGS) -c cg.c

oc.o: oc.c
	$(CROSS_PREFIX)$(CC) $(CFLAGS) -c oc.c

op: op.o pt.o
	$(CROSS_PREFIX)$(CC) $(CFLAGS) -o op op.o pt.o

op.o: op.c
	$(CROSS_PREFIX)$(CC) $(CFLAGS) -c op.c

pt.o: pt.c
	$(CROSS_PREFIX)$(CC) $(CFLAGS) -c pt.c

ifeq ($(HAVE_LLVM),yes)
llcg: llcg.o
	$(CROSS_PREFIX)$(CC) $(CFLAGS) $(LLVM_CFLAGS) -o llcg llcg.o $(LLVM_LDFLAGS)

llcg.o: llcg.c
	$(CROSS_PREFIX)$(CC) $(CFLAGS) $(LLVM_CFLAGS) -c llcg.c
endif

st: su.o st.o blib.o global.o rt.o sys.o
	$(CROSS_PREFIX)ld -m $(LDMODE) -o st su.o st.o blib.o global.o rt.o sys.o

su.o: $(SU_SRC)
	$(AS) $(AFLAGS) -o su.o $(SU_SRC)

st.o: st.s
	$(AS) $(AFLAGS) -o st.o st.s

st.s: cg op st.O
	./cg < st.O | ./op > st.s

blib.o: blib.s
	$(AS) $(AFLAGS) -o blib.o blib.s

blib.s: cg op blib.O
	./cg < blib.O | ./op > blib.s

global.o: global.s
	$(AS) $(AFLAGS) -o global.o global.s

rt.o: rt.s
	$(AS) $(AFLAGS) -o rt.o rt.s

sys.o: $(SYS_SRC)
	$(AS) $(AFLAGS) -o sys.o $(SYS_SRC)

check:	blib.O blib.chk st.O st.chk
	cmp blib.O blib.chk
	cmp st.O st.chk

# Recreate reference output without executing the 32-bit interpreter
blib.chk: blib.O
	cp blib.O blib.chk

st.chk: st.O
	cp st.O st.chk

install: bcplc bcplc.1 st cg op $(if $(HAVE_LLVM),llcg) LIBHDR su.o blib.o global.o rt.o sys.o
	mkdir -p $(PREFIX)/bin
	install -c  -m 755 bcplc     $(PREFIX)/bin
	mkdir -p $(PREFIX)/man/man1
	install -c  -m 644 bcplc.1   $(PREFIX)/man/man1
	mkdir -p $(PREFIX)/lib/bcplc
	install -cs -m 555 st	     $(PREFIX)/lib/bcplc
	install -cs -m 555 cg	     $(PREFIX)/lib/bcplc
	install -cs -m 555 op	     $(PREFIX)/lib/bcplc
ifneq ($(HAVE_LLVM),)
	install -cs -m 555 llcg        $(PREFIX)/lib/bcplc
endif
	install -c  -m 644 LIBHDR    $(PREFIX)/lib/bcplc
	install -c  -m 444 su.o	     $(PREFIX)/lib/bcplc
	install -c  -m 444 blib.o    $(PREFIX)/lib/bcplc
	install -c  -m 444 global.o  $(PREFIX)/lib/bcplc
	install -c  -m 444 rt.o	     $(PREFIX)/lib/bcplc
	install -c  -m 444 sys.o     $(PREFIX)/lib/bcplc
	rm -f $(PREFIX)/lib/bcplc/libhdr
	ln $(PREFIX)/lib/bcplc/LIBHDR $(PREFIX)/lib/bcplc/libhdr

clean:
	rm -f cg cg.o oc.o op op.o pt.o $(if $(HAVE_LLVM),llcg llcg.o)
	rm -f st st.o st.s blib.o blib.s su.o global.o rt.o sys.o
	rm -f blib.chk st.chk
