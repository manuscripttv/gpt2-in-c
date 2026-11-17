# FDUMP

## Overview

- hexdmp: a replica of xxd. 

## hexdmp

### features 

- [x] read a file. no inline.
- [x] output format: 
    - position in hex, followed by
    - hex values in byte pairs, followed by
    - literal text
    - 16 bytes. in pairs of 2 bytes
- [x] 16 bytes only per line
- [x] proper error handling

### test cases

- [x] D1 ./fdump hello.txt
        exit 0
        output 00000000: 4865 6c6c 6f2c 2077 6f72 6c64 210a Hello, world!.

- [x] D2 diff <(./fdump hello.txt) <(xxd hello.txt)
        exit 0
        output none

- [x] D3 ./fdump empty.bin
        exit 0
        output none

- [x] D4 diff <(./fdump b17.bin) <(xxd b17.bin)
        exit 0
        output 0

- [x] D5 ./fdump nope
        exit 1
        output: none

- [x] D6 ./fdump nope 2>/dev/null
        exit 1
        output: none 

- [x] D7 ./fdump secret.txt
        exit 1
        output: fdump: secret.txt: Permission denied
   
