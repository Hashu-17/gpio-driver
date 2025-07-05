#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#include <stdio.h>
#include <stdlib.h>

#define TEST_ASSERT(expr) do { \
    if (!(expr)) { \
        printf("FAIL: %s:%d: %s\n", __FILE__, __LINE__, #expr); \
        exit(1); \
    } \
} while (0)

#endif
