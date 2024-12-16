#include "excel_utils.h"
#include <time.h>
#include <string.h>

void save_vector_to_csv(const uint64_t *vec, size_t size_64, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    // Write bit positions separated by commas
    int first = 1;
    for (size_t i = 0; i < size_64; i++) {
        uint64_t word = vec[i];
        for (int bit = 0; bit < 64; bit++) {
            if (word & (1ULL << bit)) {
                if (!first) {
                    fprintf(fp, ",");
                }
                fprintf(fp, "%lu", i * 64 + bit);
                first = 0;
            }
        }
    }
    fprintf(fp, "\n");
    
    fclose(fp);
}