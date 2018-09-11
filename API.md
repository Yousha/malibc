# MalibC API Reference

**Version**: 1.0.0.1 
**ABI**: x86-64 Linux (System V)  

## Core Functionality

### Version Reporting
```c
const char *gnu_get_libc_version(void);
```

### Memory Management
```c
void* malloc(size_t size);

void free(void* ptr);
```

### Standard I/O
```c
int putchar(int c);

int printf(const char* fmt, ...);
```

### File Operations
```c
FILE* fopen(const char* path, const char* mode);

size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream);

int fclose(FILE* stream);
```

## System Interfaces

### Startup
```nasm
; Program entry point (_start)
; Stack layout on entry:
;   rsp   -> argc
;   rsp+8 -> argv[0]
; Clobbers: rbp, rcx, r11
```

### Type Definitions
```c
typedef unsigned long size_t;  // Size type (32/64-bit compatible).
#define NULL ((void*)0)        // Null pointer constant.
```

## Limitations

| Feature          | Status        | Notes                          |
|------------------|---------------|--------------------------------|
| Buffered I/O     | ❌ Not implemented | Direct syscalls only       |
| Thread Safety    | ❌ Not thread-safe | Single-threaded only      |
| Error Reporting  | ⚠️ Limited     | Only NULL/EOF returns      |
| Floating Point   | ❌ Not supported | No %f in printf          |

## Example Usage

### Basic Program
```c
#include <stdio.h>

int main() {
    printf("Allocated %zu bytes\n", sizeof(int) * 100);
    int* arr = malloc(sizeof(int) * 100);
    free(arr);
    return 0;
}
```

### File Operations
```c
FILE* f = fopen("data.txt", "r");
if (f) {
    char buf[100];
    size_t n = fread(buf, 1, sizeof(buf), f);
    printf("Read %zu bytes\n", n);
    fclose(f);
}
```

## Compliance

| Standard        | Support Level |
|----------------|---------------|
| ANSI C89       | Partial       |
| POSIX          | Minimal       |
| Linux ABI      | Full          |

> **Note**: For production systems, consider linking with full libc implementations like glibc or musl.
