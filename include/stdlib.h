#pragma once
// The `#pragma once` directive ensures that this header file is included only once 
// during the compilation process, preventing multiple inclusions and potential redefinition errors.

#include <stddef.h>
// Includes the standard definitions header, which provides common types like `size_t`.

/**
 * @brief Allocates a block of memory on the heap.
 * 
 * This function allocates a block of memory of at least `size` bytes and returns 
 * a pointer to the beginning of the block. The allocated memory is not initialized.
 * 
 * @param size The number of bytes to allocate.
 * @return void* Returns a pointer to the allocated memory on success. 
 *               If the allocation fails (e.g., insufficient memory), returns NULL.
 */
void* malloc(size_t size);

/**
 * @brief Frees a block of allocated memory.
 * 
 * This function deallocates the memory block pointed to by `ptr`, making it available 
 * for future allocations. If `ptr` is NULL, no action is performed.
 * 
 * @param ptr A pointer to the memory block to deallocate. If NULL, the function does nothing.
 */
void free(void* ptr);

/**
 * @brief Terminates the program with a specified status code.
 * 
 * This function terminates the calling process immediately. Any open file streams 
 * are flushed and closed, and control is returned to the host environment.
 * 
 * @param status The exit status code. By convention:
 *               - 0 indicates successful termination.
 *               - Non-zero values indicate abnormal termination or specific error codes.
 */
void exit(int status);
