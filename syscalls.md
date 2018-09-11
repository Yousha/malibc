# System Call Interface

**Architecture**: x86-64 (AMD64)  
**ABI**: Linux System V  
**Calling Convention**: Direct syscall invocation  

## Table of Implemented Syscalls

| Syscall # | Name    | Parameters               | Return Value       | libc Wrapper     |
|-----------|---------|--------------------------|--------------------|------------------|
| 0         | read    | fd, buf, count           | Bytes read or -1   | fread()          |
| 1         | write   | fd, buf, count           | Bytes written or -1| printf(), putchar() |
| 2         | open    | pathname, flags          | FD or -1           | fopen()          |
| 3         | close   | fd                       | 0 or -1            | fclose()         |
| 60        | exit    | status                   | Does not return    | N/A              |

## Calling Convention

### Assembly-Level Interface
```nasm
; Syscall invocation template:
mov rax, <syscall_number>
mov rdi, <arg1>
mov rsi, <arg2>
mov rdx, <arg3>
syscall
```

### Register Usage
| Register | Purpose               | Preserved? |
|----------|-----------------------|------------|
| rax      | Syscall number/return | No         |
| rdi      | 1st parameter         | No         |
| rsi      | 2nd parameter         | No         |
| rdx      | 3rd parameter         | No         |
| rcx      | Clobbered by syscall  | No         |
| r11      | Clobbered by syscall  | No         |

## Error Handling

Syscalls return:
- Non-negative values: Success
- -1: Error occurred (no `errno` support in this minimal implementation)

Common error cases:
```c
#define EFAULT  14  // Bad address
#define EINVAL  22  // Invalid argument
#define ENOMEM  12  // Out of memory
```

## libc Wrapper Implementation

### syscall() Function
```c
/**
 * @brief Generic syscall wrapper
 * @param num Syscall number
 * @param arg1 First parameter
 * @param arg2 Second parameter
 * @param arg3 Third parameter
 * @return Syscall result
 * 
 * @note Clobbers rcx and r11 per ABI requirements
 */
long syscall(long num, long arg1, long arg2, long arg3);
```

## Examples

### Direct Syscall Invocation
```c
// Write "Hello" to stdout without libc
const char msg[] = "Hello\n";
syscall(1, 1, msg, sizeof(msg)-1);  // SYS_write = 1
```

### File Operations
```nasm
; Open file in assembly
mov rax, 2        ; SYS_open
mov rdi, filename ; Path
mov rsi, 0        ; O_RDONLY
syscall
```

## Security Considerations

1. **No Parameter Validation**:
   - Wrappers pass arguments directly to kernel
   - Malformed pointers may cause crashes

2. **No Signal Handling**:
   - Syscalls may be interrupted (no automatic restart)

3. **No Atomic Guarantees**:
   - Partial reads/writes possible
   - Callers must handle short counts

## Performance Characteristics

| Operation        | Cycles (approx) | Notes                     |
|------------------|-----------------|---------------------------|
| Syscall overhead | ~100-200        | Context switch penalty    |
| Minimal wrapper  | ~10             | Argument shuffling        |
| Buffered I/O     | N/A             | No buffering in this impl |

> **Note**: This interface is designed for bare-metal and educational use. Production systems should use full libc implementations for proper error handling and portability.
