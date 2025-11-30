#include <stdio.h>
#include <stdlib.h>

#include "tools.h"

#define INITIAL_CAPACITY 10

char **input_to_grid(const char *filename) {
    char **lines = NULL;
    int num_lines = 0;
    int capacity = INITIAL_CAPACITY;

    // Open file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return NULL;
    }

    // Allocate initial array (with space for NULL terminator)
    lines = (char **) malloc((capacity + 1) * sizeof(char *));
    if (lines == NULL) {
        printf("Error: Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    // Read file line by line
    char *line;
    while ((line = read_line(file)) != NULL) {
        // Grow array if needed
        if (num_lines >= capacity) {
            capacity *= 2;
            char **temp = (char **) realloc(lines, (capacity + 1) * sizeof(char *));
            if (temp == NULL) {
                printf("Error: Memory reallocation failed\n");
                free(line);
                for (int i = 0; i < num_lines; i++) {
                    free(lines[i]);
                }
                free(lines);
                fclose(file);
                return NULL;
            }
            lines = temp;
        }
        lines[num_lines] = line;
        num_lines++;
    }

    // Add NULL terminator
    lines[num_lines] = NULL;

    fclose(file);

    return lines;
}
