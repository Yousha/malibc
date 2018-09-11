#pragma once
// The `#pragma once` directive ensures that this header file is included only once 
// during the compilation process, preventing multiple inclusions and potential redefinition errors.

#include <stddef.h>
// Includes the standard definitions header, which provides common types like `size_t`.

/**
 * @brief Represents a file stream.
 * 
 * This typedef defines `FILE` as a pointer to `void`, serving as an opaque type 
 * for file streams. It abstracts the underlying implementation details of file handling.
 */
#define FILE void*

/**
 * @brief Opens a file and associates it with a stream.
 * 
 * @param path A null-terminated string specifying the file path to open.
 * @param mode A null-terminated string specifying the access mode (e.g., "r", "w", "a").
 *             Common modes include:
 *             - "r" for reading
 *             - "w" for writing (creates or truncates the file)
 *             - "a" for appending
 * @return FILE* Returns a pointer to the opened file stream on success, or NULL on failure.
 */
FILE* fopen(const char* path, const char* mode);

/**
 * @brief Reads data from a file stream into a buffer.
 * 
 * @param ptr A pointer to the buffer where the read data will be stored.
 * @param size The size (in bytes) of each element to read.
 * @param nmemb The number of elements to read.
 * @param stream A pointer to the file stream to read from.
 * @return size_t Returns the number of elements successfully read. If an error occurs 
 *                or the end of the file is reached, the return value may be less than `nmemb`.
 */
size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream);

/**
 * @brief Closes a file stream.
 * 
 * @param stream A pointer to the file stream to close.
 * @return int Returns 0 on success, or EOF if an error occurs.
 */
int fclose(FILE* stream);

/**
 * @brief Writes a single character to the standard output.
 * 
 * @param c The character to write (as an integer, typically cast from `char`).
 * @return int Returns the character written on success, or EOF on failure.
 */
int _putchar(int c);

/**
 * @brief Formats and writes output to the standard output.
 * 
 * @param fmt A format string specifying how subsequent arguments are converted for output.
 * @param ... Additional arguments whose values are formatted and printed according to `fmt`.
 * @return int Returns the number of characters written on success, or a negative value on failure.
 */
int _printf(const char* fmt, ...);

/**
 * @brief Alias for `_putchar`.
 * 
 * This macro maps the standard `putchar` function to the custom `_putchar` implementation.
 */
#define putchar _putchar

/**
 * @brief Alias for `_printf`.
 * 
 * This macro maps the standard `printf` function to the custom `_printf` implementation.
 */
#define printf _printf

/**
 * @brief Get libc version string
 * @return Constant string in format "malibc-1.0.0.1"
 * 
 * @note Provides compatibility with some GNU extensions
 * @warning Not actually GNU libc - returns our version
 */
const char *get_libc_version(void);
