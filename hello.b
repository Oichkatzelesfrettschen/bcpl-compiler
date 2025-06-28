GET "libhdr"

MANIFEST {
  LF = *n10 // Linefeed character
}

LET START() = VALOF
$(
  WRITES("Hello, x86_64 World!")
  WRCH(LF)
  RESULTIS 0
$)
