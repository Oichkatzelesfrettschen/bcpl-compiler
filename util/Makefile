# Makefile for bcplc/util

BC ?= $(shell command -v bcplc 2>/dev/null || echo ../src/bcplc)
BFLAGS ?= -O

all: cmpltest xref gpm

cmpltest: cmpltest.bcpl
	$(BC) $(BFLAGS) cmpltest.bcpl

xref: xref.bcpl
	$(BC) $(BFLAGS) xref.bcpl

gpm: gpm.bcpl
	$(BC) $(BFLAGS) gpm.bcpl

test: cmpltest
	./cmpltest

install:

clean:
	rm -f cmpltest cmpltest.o
	rm -f xref xref.o
	rm -f gpm gpm.o
.PHONY: all test install clean
