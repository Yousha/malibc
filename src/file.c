#include <stdio.h>
#include <syscalls.h>  // Assumed to provide `open`, `read`, and `close` system calls.
#include <stdlib.h>

/**
 * @brief Opens a file and associates it with a stream.
 * 
 * This function simplifies file opening by mapping modes like "r" and "w" to flags
 * used by the `open` system call. The file descriptor is cast to a `FILE*` for compatibility.
 * 
 * @param path A null-terminated string specifying the file path to open.
 * @param mode A null-terminated string specifying the access mode (e.g., "r", "w").
 *             - "r": Open for reading.
 *             - "w": Open for writing, create if it doesn't exist, truncate if it does.
 * @return FILE* Returns a pointer to the opened file stream on success, or NULL on failure.
 */
FILE* fopen(const char* path, const char* mode) {
    int flags = 0;
    // Simplified mode parsing.
    if (mode[0] == 'r') flags = 0;        // O_RDONLY (read-only)
    if (mode[0] == 'w') flags = 0x241;    // O_WRONLY|O_CREAT|O_TRUNC (write-only, create, truncate)
    int fd = open(path, flags);           // System call to open the file.
    return (fd >= 0) ? (FILE*)(long)fd : NULL;  // Return the file descriptor as a FILE*
}

/**
 * @brief Reads data from a file stream into a buffer.
 * 
 * This function reads up to `size * nmemb` bytes from the file associated with `stream`
 * into the buffer pointed to by `ptr`. The number of items successfully read is returned.
 * 
 * @param ptr A pointer to the buffer where the read data will be stored.
 * @param size The size (in bytes) of each element to read.
 * @param nmemb The number of elements to read.
 * @param stream A pointer to the file stream to read from.
 * @return size_t Returns the number of elements successfully read. If an error occurs
 *                or the end of the file is reached, the return value may be less than `nmemb`.
 */
size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    int fd = (long)stream;  // Cast the FILE* back to a file descriptor.
    return read(fd, ptr, size * nmemb) / size;  // Read data and calculate the number of elements.
}

/**
 * @brief Closes a file stream.
 * 
 * This function closes the file associated with the given stream by invoking the `close`
 * system call on the underlying file descriptor.
 * 
 * @param stream A pointer to the file stream to close.
 * @return int Returns 0 on success, or -1 if an error occurs.
 */
int fclose(FILE* stream) {
    return close((long)stream);  // Close the file descriptor.
}
