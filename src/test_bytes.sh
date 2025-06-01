#!/bin/bash
echo "Byte (Dec) | Byte (Hex) | Result"
echo "-----------------------------------"
for i in {0..255}; do
    printf -v hex_val "%02x" "$i"
    # Send the byte to st's stdin. Timeout after 0.5s to catch hangs.
    # stderr is redirected to stdout to capture segfault messages.
    # We check the exit code of st.
    output=$(printf "\\x$hex_val" | timeout 0.5 ./st 2>&1)
    exit_code=$?

    result="OK"
    if [ $exit_code -eq 139 ] || [ $exit_code -eq 134 ]; then # Segfault or Abort
        result="CRASH (Segfault/Abort)"
    elif [ $exit_code -eq 124 ]; then # Timeout
        result="HANG (Timeout)"
    elif [ $exit_code -ne 0 ]; then
        result="ERROR (Exit $exit_code)"
    elif [ -n "$output" ]; then # If st produced any output and exited 0
        result="OK (Output)"
    fi
    echo "$i | $hex_val | $result"
done
