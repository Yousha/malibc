#!/bin/bash

# Create obj directory.
mkdir -p obj obj/tests

# Compile core components.
as --64 src/crt0.s -o obj/crt0.o
gcc -std=gnu99 -nostdlib -ffreestanding -Iinclude -c src/syscalls.c -o obj/syscalls.o
gcc -std=gnu99 -nostdlib -ffreestanding -Iinclude -c src/stdio.c -o obj/stdio.o
gcc -std=gnu99 -nostdlib -ffreestanding -Iinclude -c src/file.c -o obj/file.o
gcc -std=gnu99 -nostdlib -ffreestanding -Iinclude -c src/string.c -o obj/string.o
gcc -std=gnu99 -nostdlib -ffreestanding -Iinclude -c src/stdlib.c -o obj/stdlib.o

# Compile tests.
gcc -std=gnu99 -nostdlib -ffreestanding -Iinclude -c tests/hello.c -o obj/tests/hello.o
gcc -std=gnu99 -nostdlib -ffreestanding -Iinclude -c tests/filetest.c -o obj/tests/filetest.o

# Link
ld -static -o hello obj/crt0.o obj/tests/hello.o obj/syscalls.o obj/stdio.o obj/file.o obj/string.o obj/stdlib.o
ld -static -o filetest obj/crt0.o obj/tests/filetest.o obj/syscalls.o obj/stdio.o obj/file.o obj/string.o obj/stdlib.o

echo "Build complete! Run:"
echo "./hello       # Basic test"
echo "./filetest    # File I/O test"
echo "Note: Create test.txt for filetest"
