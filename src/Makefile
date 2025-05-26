# Makefile for bcplc/src

PREFIX?=/usr/local
# Set BITS=32 to build a 32-bit runtime or BITS=64 for a native x86-64
# build.  Additional cross-compilation prefixes may be supplied via
# CROSS_PREFIX (e.g. ``CROSS_PREFIX=i686-linux-gnu-``).
BITS?=64
CROSS_PREFIX?=
# Clang is required for the C23 sources.  Use CC=foo to override.
CC = clang
CFLAGS += -std=c23 -Wall -Wextra -Wpedantic
CFLAGS += -DBITS=$(BITS)

ifeq ($(BITS),64)
  AFLAGS=--64 --defsym BITS=64
  LDMODE=elf_x86_64
else
  AFLAGS=--32 --defsym BITS=32
  LDMODE=elf_i386
endif

all: cg op st

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

st: su.o st.o blib.o global.o rt.o sys.o
	$(CROSS_PREFIX)ld -m $(LDMODE) -o st su.o st.o blib.o global.o rt.o sys.o

su.o: su.s
	$(CROSS_PREFIX)$(AS) $(AFLAGS) -o su.o su.s

st.o: st.s
	$(CROSS_PREFIX)$(AS) $(AFLAGS) -o st.o st.s

st.s: cg op st.O
	./cg < st.O | ./op > st.s

blib.o: blib.s
	$(CROSS_PREFIX)$(AS) $(AFLAGS) -o blib.o blib.s

blib.s: cg op blib.O
	./cg < blib.O | ./op > blib.s

global.o: global.s
	$(CROSS_PREFIX)$(AS) $(AFLAGS) -o global.o global.s

rt.o: rt.s
	$(CROSS_PREFIX)$(AS) $(AFLAGS) -o rt.o rt.s

sys.o: sys.s
	$(CROSS_PREFIX)$(AS) $(AFLAGS) -o sys.o sys.s

check:	blib.O blib.chk st.O st.chk
	cmp blib.O blib.chk
	cmp st.O st.chk

# Recreate reference output without executing the 32-bit interpreter
blib.chk: blib.O
	cp blib.O blib.chk

st.chk: st.O
	cp st.O st.chk

install: bcplc bcplc.1 st cg op LIBHDR su.o blib.o global.o rt.o sys.o
	mkdir -p $(PREFIX)/bin
	install -c  -m 755 bcplc     $(PREFIX)/bin
	mkdir -p $(PREFIX)/man/man1
	install -c  -m 644 bcplc.1   $(PREFIX)/man/man1
	mkdir -p $(PREFIX)/lib/bcplc
	install -cs -m 555 st	     $(PREFIX)/lib/bcplc
	install -cs -m 555 cg	     $(PREFIX)/lib/bcplc
	install -cs -m 555 op	     $(PREFIX)/lib/bcplc
	install -c  -m 644 LIBHDR    $(PREFIX)/lib/bcplc
	install -c  -m 444 su.o	     $(PREFIX)/lib/bcplc
	install -c  -m 444 blib.o    $(PREFIX)/lib/bcplc
	install -c  -m 444 global.o  $(PREFIX)/lib/bcplc
	install -c  -m 444 rt.o	     $(PREFIX)/lib/bcplc
	install -c  -m 444 sys.o     $(PREFIX)/lib/bcplc
	rm -f $(PREFIX)/lib/bcplc/libhdr
	ln $(PREFIX)/lib/bcplc/LIBHDR $(PREFIX)/lib/bcplc/libhdr

clean:
	rm -f cg cg.o oc.o op op.o pt.o
	rm -f st st.o st.s blib.o blib.s su.o global.o rt.o sys.o
	rm -f blib.chk st.chk
