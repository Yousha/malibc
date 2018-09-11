/**
 * @file syscalls.h
 * @brief Linux x86-64 System Call Interfaces
 */

#pragma once
#include <stddef.h>

/**
 * @brief Calculates the length of a null-terminated string.
 * @param s Pointer to the null-terminated string.
 * @return size_t Returns the number of characters in the string, excluding the null terminator.
 */
size_t strlen(const char* s);

/**
 * @brief Copies a block of memory from one location to another.
 * @param dest Pointer to the destination memory block.
 * @param src Pointer to the source memory block.
 * @param n Number of bytes to copy.
 * @return void* Returns a pointer to the destination memory block.
 */
void* memcpy(void* dest, const void* src, size_t n);
