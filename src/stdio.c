#include <stdio.h>
#include <syscalls.h>  // Assumed to provide the `write` system call.

/**
 * @brief Writes a single character to the standard output.
 * 
 * This function writes a single character to file descriptor `1` (standard output)
 * using the `write` system call.
 * 
 * @param c The character to write (as an integer, typically cast from `char`).
 * @return int Returns the character written on success, or -1 if an error occurs.
 */
int _putchar(int c) {
    char ch = c;  // Convert the integer character to a `char`.
    return write(1, &ch, 1);  // Write 1 byte to file descriptor 1 (stdout).
}

/**
 * @brief Simplified implementation of formatted output to the standard output.
 * 
 * This function writes the format string `fmt` directly to the standard output
 * without processing any format specifiers. It calculates the length of the string
 * and writes it using the `write` system call.
 * 
 * @param fmt A null-terminated format string to write.
 * @param ... Variadic arguments (ignored in this implementation).
 * @return int Returns the number of characters written on success, or 0 if the string is empty.
 */
int _printf(const char* fmt, ...) {
    const char *p = fmt;  // Pointer to the format string.
    size_t count = 0;

    // Calculate the length of the format string.
    while (p[count] != '\0') count++;

    // If the string is not empty, write it to standard output.
    if (count > 0) write(1, fmt, count);

    return count;  // Return the number of characters written.
}
