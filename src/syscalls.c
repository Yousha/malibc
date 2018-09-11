#include <syscalls.h>

/**
 * @brief Invokes a system call with the specified number and arguments.
 * 
 * This function uses the x86-64 System V ABI to perform a system call via the `syscall` instruction.
 * 
 * @param num System call number.
 * @param arg1 First argument to the system call.
 * @param arg2 Second argument to the system call.
 * @param arg3 Third argument to the system call.
 * @return long Returns the result of the system call, which is system-dependent.
 */
long syscall(long num, long arg1, long arg2, long arg3) {
    long ret;
    __asm__ volatile (
        "syscall"               // Perform the system call.
        : "=a"(ret)             // Output: Result is stored in RAX.
        : "a"(num),             // Input: System call number in RAX.
          "D"(arg1),            // Input: First argument in RDI.
          "S"(arg2),            // Input: Second argument in RSI.
          "d"(arg3)             // Input: Third argument in RDX.
        : "rcx", "r11", "memory" // Clobbered registers and memory.
    );
    return ret;
}

/**
 * @brief Writes data from a buffer to a file descriptor.
 * 
 * @param fd File descriptor to write to.
 * @param buf Pointer to the buffer containing the data to write.
 * @param count Number of bytes to write.
 * @return int Returns the number of bytes written on success, or -1 on error.
 */
int write(int fd, const void* buf, size_t count) {
    return syscall(1, fd, (long)buf, count);  // SYS_write = 1
}

/**
 * @brief Opens a file with specified flags.
 * 
 * @param path Path to the file to open.
 * @param flags Flags specifying the access mode (e.g., O_RDONLY, O_WRONLY).
 * @return int Returns the file descriptor on success, or -1 on error.
 */
int open(const char* path, int flags) {
    return syscall(2, (long)path, flags, 0);  // SYS_open = 2
}

/**
 * @brief Closes an open file descriptor.
 * 
 * @param fd File descriptor to close.
 * @return int Returns 0 on success, or -1 on error.
 */
int close(int fd) {
    return syscall(3, fd, 0, 0);  // SYS_close = 3
}

/**
 * @brief Reads data from a file descriptor into a buffer.
 * 
 * @param fd File descriptor to read from.
 * @param buf Pointer to the buffer where the read data will be stored.
 * @param count Number of bytes to read.
 * @return size_t Returns the number of bytes read on success, or -1 on error.
 */
size_t read(int fd, void* buf, size_t count) {
    return syscall(0, fd, (long)buf, count);  // SYS_read = 0
}
