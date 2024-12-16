#ifndef DEBUG_UTILS_H
#define DEBUG_UTILS_H

#include <stdint.h>
#include <stdio.h>
#include "excel_utils.h"

// Print binary representation of a uint64_t number
void print_binary(uint64_t n) {
    for (int i = 63; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 8 == 0) printf(" ");
    }
    printf("\n");
}

// Debug vector contents in binary format
void debug_vector_binary(const uint64_t *vec, size_t size, const char *label) {
    printf("\n=== %s ===\n", label);
    for (size_t i = 0; i < size; i++) {
        printf("[%zu]: ", i);
        print_binary(vec[i]);
    }
    printf("\n");
}

#endif