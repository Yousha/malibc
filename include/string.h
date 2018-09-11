#pragma once
#include <stddef.h>

/**
 * @brief Invokes a system call with the specified number and arguments.
 * @param num System call number.
 * @param arg1 First argument to the system call.
 * @param arg2 Second argument to the system call.
 * @param arg3 Third argument to the system call.
 * @return long Returns the result of the system call, which is system-dependent.
 */
long syscall(long num, long arg1, long arg2, long arg3);

/**
 * @brief Writes data from a buffer to a file descriptor.
 * @param fd File descriptor to write to.
 * @param buf Pointer to the buffer containing the data to write.
 * @param count Number of bytes to write.
 * @return int Returns the number of bytes written on success, or -1 on error.
 */
int write(int fd, const void* buf, size_t count);
