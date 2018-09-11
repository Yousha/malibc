#include <stdlib.h>
#include <stddef.h>

// A static array representing a simple heap of 1MB size.
static char heap[1024 * 1024];  // 1MB heap
static size_t heap_ptr = 0;     // Tracks the current position in the heap.

/**
 * @brief Allocates a block of memory on the heap.
 * 
 * This function implements a simple bump allocator. It allocates memory by incrementing
 * a pointer (`heap_ptr`) within the static `heap` array. If the requested size exceeds
 * the remaining available space, the allocation fails and returns NULL.
 * 
 * @param size The number of bytes to allocate.
 * @return void* Returns a pointer to the allocated memory on success, or NULL if the
 *               allocation fails due to insufficient space.
 */
void* malloc(size_t size) {
    // Check if the requested size fits within the remaining heap space.
    if (heap_ptr + size > sizeof(heap)) return NULL;

    // Allocate memory by returning the current heap pointer and advancing it.
    void* ptr = &heap[heap_ptr];
    heap_ptr += size;
    return ptr;
}

/**
 * @brief Deallocates a block of memory.
 * 
 * This function is a no-op in this implementation because the bump allocator does not
 * support deallocation. Memory cannot be reclaimed or reused once allocated.
 * 
 * @param ptr A pointer to the memory block to deallocate. This parameter is ignored.
 */
void free(void* ptr) {}  // No-op (bump allocator)
