/**
 * @file stddef.h
 * @brief Standard Type Definitions
 */

#pragma once

/**
 * @brief Unsigned size type
 *
 * Used for object sizes and array indices. Guaranteed to be large enough
 * to represent the size of any object that can be declared in C.
 *
 * @note In this implementation, maps directly to `unsigned long`
 * @warning Not suitable for 128-bit systems
 */
typedef unsigned long size_t;

/**
 * @brief Null pointer constant
 *
 * Expands to a null pointer constant of type `void*`. 
 * This implementation uses the standard ((void*)0) definition.
 *
 * @par Example:
 * @code
 * int *ptr = NULL;
 * if (ptr == NULL) { ... }
 * @endcode
 */
#define NULL ((void*)0)
