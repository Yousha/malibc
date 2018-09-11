#include <string.h>
#include <stddef.h>

/**
 * @brief Calculates the length of a null-terminated string.
 * @param s Pointer to the input string.
 * @return size_t Returns the number of characters in the string, excluding the null terminator.
 */
size_t strlen(const char* s) {
    size_t len = 0;
    while (s[len]) len++;
    return len;
}

/**
 * @brief Copies a block of memory from one location to another.
 * @param dest Pointer to the destination memory block.
 * @param src Pointer to the source memory block.
 * @param n Number of bytes to copy.
 * @return void* Returns a pointer to the destination memory block.
 */
void* memcpy(void* dest, const void* src, size_t n) {
    char* d = dest;
    const char* s = src;
    while (n--) *d++ = *s++;
    return dest;
}
