/**
 * @file crt0.s
 * @brief x86-64 C Runtime Startup (Bare-metal/Static Linkage)
 *
 * @section Description
 * Sets up the execution environment for C programs:
 * 1. Clears the base pointer (RBP)
 * 2. Gets argc/argv from stack
 * 3. Aligns stack to 16-byte boundary (SysV ABI requirement)
 * 4. Calls main() with proper arguments
 * 5. Handles program exit via sys_exit
 *
 * @section ABI Compliance
 * - Follows System V AMD64 ABI:
 *   - Stack alignment: 16-byte before call
 *   - Argument passing: RDI (argc), RSI (argv)
 *   - Return value: RAX -> exit status
 *
 * @section Registers Clobbered
 * - RBP (explicitly zeroed)
 * - RSP (modified for alignment)
 * - RAX/RDI/RSI (syscall args)
 * - RCX/R11 (syscall clobbers)
 *
 * @section Syscalls Used
 * - SYS_exit (60): Program termination
 *
 * @note For Linux x86-64 systems only
 * @warning Not thread-safe (single-threaded environments only)
 */
.section .text
.global _start
/**
 * @brief Entry point for static binaries
 * 
 * Stack Layout on Entry:
 * [rsp]    = argc
 * [rsp+8]  = argv[0]
 * [rsp+16] = argv[1]
 * ...
 * 
 * Registers:
 * @clob rbp, rsp, rdi, rsi, rax, rcx, r11
 */
_start:
    xor %rbp, %rbp        # Clear frame pointer (ABI requirement)
    pop %rdi              # argc = stack[0]
    mov %rsp, %rsi        # argv = stack[1..]
    and $-16, %rsp        # Align stack to 16 bytes
    call main             # Transfer to C code
    mov %rax, %rdi        # exit(status)
    mov $60, %rax         # SYS_exit
    syscall
