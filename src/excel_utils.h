#ifndef EXCEL_UTILS_H
#define EXCEL_UTILS_H

#include <stdint.h>
#include <stdio.h>

// Save bit positions to CSV file
void save_vector_to_csv(const uint64_t *vec, size_t size_64, const char *filename);

#endif