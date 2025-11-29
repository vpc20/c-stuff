#define INITIAL_LINE_SIZE 128
#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

// Function to read a line of arbitrary length
char *read_line(FILE *file) {
    size_t capacity = INITIAL_LINE_SIZE;
    size_t len = 0;
    char *line = (char *) malloc(capacity * sizeof(char));

    if (line == NULL) {
        return NULL;
    }

    int c;
    while ((c = fgetc(file)) != EOF && c != '\n') {
        // Grow buffer if needed
        if (len + 1 >= capacity) {
            capacity *= 2;
            char *temp = (char *) realloc(line, capacity * sizeof(char));
            if (temp == NULL) {
                free(line);
                return NULL;
            }
            line = temp;
        }
        line[len++] = c;
    }

    // If we read nothing and hit EOF, return NULL
    if (len == 0 && c == EOF) {
        free(line);
        return NULL;
    }

    line[len] = '\0';
    return line;
}