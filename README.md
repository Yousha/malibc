# MalibC (discontinued)

A super lightweight C standard library implementation for x86-64 Linux systems was designed for manipulating PC motherboard firmware, but the project was discontinued.
(The author of the assembly(CRt0.s) file is another person)

## Features

- **Core functionality**:
  - Memory allocation (`malloc/free`)
  - Standard I/O (`printf/putchar`)
  - File operations (`fopen/fread/fclose`)
  - System call wrappers

- **Minimal footprint**:
  - Static 1MB heap
  - No buffered I/O
  - ~50KB binary size

- **Compatibility**:
  - x86-64 Linux (System V ABI)
  - Partial ANSI C89 support
  - GNU extension stubs

## Quick start

```bash
./build.sh

# Run examples
./hello
./filetest
```

## API reference

See detailed documentation:
- [API.md](docs/API.md) - Library functions
- [syscalls.md](docs/syscalls.md) - Low-level interfaces

## Limitations

❌ No dynamic linking  
❌ No thread safety  
❌ Limited error handling  
❌ No floating point support  

## Example usage

```c
#include <stdio.h>

int main() {
    printf("malibc version: %s\n", get_libc_version());
    
    FILE* f = fopen("test.txt", "r");
    if (f) {
        char buf[100];
        size_t n = fread(buf, 1, sizeof(buf), f);
        printf("Read %zu bytes\n", n);
        fclose(f);
    }
    return 0;
}
```
