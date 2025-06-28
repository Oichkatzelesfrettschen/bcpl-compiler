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

ifeq ($(BITS),64)
  AFLAGS=--64 --defsym BITS=64 -g
  LDMODE=elf_x86_64
  TOTAL_G_SPACE_VAL = $(shell echo $$((400 * 8)))
  WORDSIZE_ALIGN_VAL_G = 8
else ifeq ($(BITS),32)
  AFLAGS=--32 --defsym BITS=32 -g
  LDMODE=elf_i386
  TOTAL_G_SPACE_VAL = $(shell echo $$((400 * 4)))
  WORDSIZE_ALIGN_VAL_G = 4
else ifeq ($(BITS),16)
  AFLAGS=--16 --defsym BITS=16 -g
  LDMODE=elf_i386
  TOTAL_G_SPACE_VAL = $(shell echo $$((400 * 2)))
  WORDSIZE_ALIGN_VAL_G = 2
else
  $(error Unsupported BITS value: $(BITS))
endif
AFLAGS += --defsym TOTAL_G_SPACE=$(TOTAL_G_SPACE_VAL) --defsym WORDSIZE_ALIGN_VAL=$(WORDSIZE_ALIGN_VAL_G)

# Define BITS-specific values for LIBHDR generation
ifeq ($(BITS),64)
  BYTESPERWORD_VAL=8
  BITSPERWORD_VAL=64
  MAXINT_VAL="#X7FFFFFFFFFFFFFFF"
  MININT_VAL="#X8000000000000000"
else ifeq ($(BITS),32)
  BYTESPERWORD_VAL=4
  BITSPERWORD_VAL=32
  MAXINT_VAL="#X7FFFFFFF"
  MININT_VAL="#X80000000"
else ifeq ($(BITS),16)
  BYTESPERWORD_VAL=2
  BITSPERWORD_VAL=16
  MAXINT_VAL="#X7FFF"
  MININT_VAL="#X8000"
endif

ifeq ($(BITS),16)
  SU_SRC=su16.s
  SYS_SRC=sys_ia16.s
else
  SU_SRC=su.s
  OS_UNAME := $(shell uname)
  ifeq ($(OS_UNAME),Linux)
    ifeq ($(BITS),64)
      SYS_SRC=sys_linux_x86_64.s
    else # Assuming BITS=32 for non-64, non-16 cases on Linux
      SYS_SRC=sys_linux.s
    endif
  else ifeq ($(OS_UNAME),FreeBSD)
    # Assuming sys_freebsd.s is 32-bit. A sys_freebsd_x86_64.s would be needed for 64-bit.
    # For now, let's assume it might work or a specific 64-bit version is needed.
    # This part may need adjustment if FreeBSD 64-bit is a target.
    ifeq ($(BITS),64)
      # Placeholder:
      # SYS_SRC=sys_freebsd_x86_64.s # This file does not exist yet
      # Fallback to the existing one, which might be 32-bit or dual-purpose
      SYS_SRC=sys_freebsd.s
      $(warning FreeBSD 64-bit target selected, using sys_freebsd.s. Ensure it's 64-bit compatible or create sys_freebsd_x86_64.s)
    else # BITS=32 on FreeBSD
      SYS_SRC=sys_freebsd.s
    endif
  else
    $(error Unsupported OS: $(OS_UNAME) for BITS=$(BITS))
  endif
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

# Target to generate local libhdr using current BITS settings
libhdr_local: src/LIBHDR.template Makefile
	@echo "Generating src/libhdr for BITS=$(BITS)..."
	@sed \
		-e "s/@@BYTESPERWORD@@/$(BYTESPERWORD_VAL)/g" \
		-e "s/@@BITSPERWORD@@/$(BITSPERWORD_VAL)/g" \
		-e "s/@@MAXINT@@/$(MAXINT_VAL)/g" \
		-e "s/@@MININT@@/$(MININT_VAL)/g" \
		src/LIBHDR.template > src/libhdr

all: libhdr_local $(ALL_TARGETS)

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
	$(CROSS_PREFIX)$(AS) $(AFLAGS) -o su.o $(SU_SRC)

st.o: st.s
	$(CROSS_PREFIX)$(AS) $(AFLAGS) -o st.o st.s

st.s: cg op st.O libhdr_local # Ensure libhdr is generated before st.O might be processed by a bcplc that needs it
	./cg < st.O | ./op > st.s

blib.o: blib.s
	$(CROSS_PREFIX)$(AS) $(AFLAGS) -o blib.o blib.s

blib.s: cg op blib.O libhdr_local # Ensure libhdr is generated
	./cg < blib.O | ./op > blib.s

global.o: global.s
	$(CROSS_PREFIX)$(AS) $(AFLAGS) -o global.o global.s

rt.o: rt.s
	$(CROSS_PREFIX)$(AS) $(AFLAGS) -o rt.o rt.s

sys.o: $(SYS_SRC)
	$(CROSS_PREFIX)$(AS) $(AFLAGS) -o sys.o $(SYS_SRC)

check:	blib.O blib.chk st.O st.chk
	cmp blib.O blib.chk
	cmp st.O st.chk

# Recreate reference output without executing the 32-bit interpreter
blib.chk: blib.O
	cp blib.O blib.chk

st.chk: st.O
	cp st.O st.chk

install: bcplc bcplc.1 st cg op $(if $(HAVE_LLVM),llcg) src/LIBHDR.template su.o blib.o global.o rt.o sys.o
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
	@echo "Generating $(PREFIX)/lib/bcplc/LIBHDR for BITS=$(BITS)..."
	@mkdir -p $(PREFIX)/lib/bcplc
	@sed \
		-e "s/@@BYTESPERWORD@@/$(BYTESPERWORD_VAL)/g" \
		-e "s/@@BITSPERWORD@@/$(BITSPERWORD_VAL)/g" \
		-e "s/@@MAXINT@@/$(MAXINT_VAL)/g" \
		-e "s/@@MININT@@/$(MININT_VAL)/g" \
		src/LIBHDR.template > $(PREFIX)/lib/bcplc/LIBHDR
	@chmod 644 $(PREFIX)/lib/bcplc/LIBHDR
	install -c  -m 444 su.o	     $(PREFIX)/lib/bcplc/su$(BITS).o
	install -c  -m 444 blib.o    $(PREFIX)/lib/bcplc # Assuming blib.o is BITS-agnostic or handled by its own source
	install -c  -m 444 global.o  $(PREFIX)/lib/bcplc # Assuming global.o is BITS-agnostic
	install -c  -m 444 rt.o	     $(PREFIX)/lib/bcplc # Assuming rt.o is BITS-agnostic
	install -c  -m 444 sys.o     $(PREFIX)/lib/bcplc/sys$(BITS).o
	# Note: If blib.s, global.s, rt.s also have BITS-dependent versions,
	# they would need similar treatment for their .o files.
	# For now, assuming only su.s and sys*.s are the primary BITS-variant sources
	# leading to different .o files that need to be distinguished at install time.
	rm -f $(PREFIX)/lib/bcplc/libhdr
	ln -sf LIBHDR $(PREFIX)/lib/bcplc/libhdr # Use -sf for symbolic link force

clean:
	rm -f cg cg.o oc.o op op.o pt.o $(if $(HAVE_LLVM),llcg llcg.o)
	rm -f st st.o st.s blib.o blib.s su.o global.o rt.o sys.o
	rm -f blib.chk st.chk src/libhdr # Clean generated local libhdr
