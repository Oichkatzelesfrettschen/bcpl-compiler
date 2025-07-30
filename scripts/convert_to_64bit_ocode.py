"""Simple converter for testing 64-bit OCODE generation.

This script reads a whitespace-separated OCODE file assumed to contain
integer tokens and label references. It rewrites numeric tokens as
decimal strings suitable for a 64-bit aware code generator. Labels are
preserved verbatim. This is only a temporary tool used during the
modernization of the BCPL compiler and is not a full translator.
"""

import sys

if len(sys.argv) != 3:
    print("Usage: convert_to_64bit_ocode.py <input> <output>")
    sys.exit(1)

with open(sys.argv[1]) as f:
    data = f.read().split()

out = []
for token in data:
    if token.startswith('L'):
        out.append(token)
    else:
        try:
            num = int(token)
            out.append(str(num))
        except ValueError:
            out.append(token)

with open(sys.argv[2], 'w') as f:
    f.write(' '.join(out))
    f.write('\n')
