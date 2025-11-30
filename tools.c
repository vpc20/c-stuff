#define INITIAL_LINE_SIZE 128
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Returns a new substring from start index with specified length
// Returns NULL on error
// Caller is responsible for freeing the returned string
// char *substring(const char *str, int start, int length) {
//     // Check for NULL input
//     if (str == NULL) {
//         return NULL;
//     }
//
//     int str_len = strlen(str);
//
//     // Validate start position
//     if (start < 0 || start >= str_len) {
//         return NULL;
//     }
//
//     // Adjust length if it goes beyond string end
//     if (start + length > str_len) {
//         length = str_len - start;
//     }
//
//     // Allocate memory for substring (+1 for null terminator)
//     char *substr = (char *) malloc((length + 1) * sizeof(char));
//     if (substr == NULL) {
//         return NULL; // Memory allocation failed
//     }
//
//     // Copy the substring
//     strncpy(substr, str + start, length);
//     substr[length] = '\0'; // Add null terminator
//
//     return substr;
// }


// Caller provides the buffer (no allocation needed)
void substring(char *dest, const char *src, int start, int length) {
    // No malloc, no free needed
    strncpy(dest, src + start, length);
    dest[length] = '\0';
}

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
