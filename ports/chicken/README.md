# Experimental Chicken Scheme Port

This directory contains an experimental port of the BCPL compiler to [Chicken Scheme](https://call-cc.org/). The goal is to eventually reimplement parts of the runtime using Scheme in order to aid experimentation and prototyping.  Nothing here is built or installed by default.

## Building

The examples are intended to be built with `csc`, the Chicken Scheme compiler. For instance:

```sh
csc -o bcplc-chicken main.scm
```

## Status

This port is under heavy development. The files currently present are only stubs meant to establish the directory structure.

For a detailed implementation plan consult [ROADMAP.md](ROADMAP.md).
