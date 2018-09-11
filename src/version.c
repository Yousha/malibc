#include <stdio.h>

/**
 * Version string
 * Format: "name-major.minor.patch"
 */
static const char version_str[] = "malibc-1.0.0.1";

const char *get_libc_version(void) {
    return version_str;
}
