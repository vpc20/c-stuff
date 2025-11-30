#define INITIAL_LINE_SIZE 128
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

// -------------------------------------------------------------------------------
// Caller provides the buffer (no allocation needed)
void substring(char *dest, const char *src, int start, int length) {
    // No malloc, no free needed
    strncpy(dest, src + start, length);
    dest[length] = '\0';
}

// -------------------------------------------------------------------------------
// Trim leading whitespace
char *ltrim(char *s) {
    while (isspace((unsigned char)*s))
        s++;
    return s;
}

// Trim trailing whitespace
char *rtrim(char *s) {
    char *back = s + strlen(s) - 1;
    while (back >= s && isspace((unsigned char)*back))
        back--;
    *(back + 1) = '\0';
    return s;
}

// Trim both leading and trailing whitespace
char *trim(char *s) {
    return rtrim(ltrim(s));
}

// -------------------------------------------------------------------------------
// the delimiter can be any one of the char in delim or the whole delim itself
char **str_split(const char *str, const char *delim) {
    // Make a copy since strtok modifies the string
    char *str_copy = malloc(strlen(str) + 1);
    if (!str_copy) return NULL;
    strcpy(str_copy, str);

    // Count tokens first
    int count = 0;
    char *token = strtok(str_copy, delim);
    while (token != NULL) {
        count++;
        token = strtok(NULL, delim);
    }

    // Allocate array
    char **str_arr = malloc((count + 1) * sizeof(char *));
    if (!str_arr) {
        free(str_copy);
        return NULL;
    }

    // Copy string again for second pass
    strcpy(str_copy, str);

    // Split and store tokens
    int idx = 0;
    token = strtok(str_copy, delim);
    while (token != NULL) {
        str_arr[idx] = malloc(strlen(token) + 1);
        strcpy(str_arr[idx], token);
        idx++;
        token = strtok(NULL, delim);
    }

    str_arr[idx] = NULL;
    free(str_copy);
    return str_arr;
}

// -------------------------------------------------------------------------------
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

// -------------------------------------------------------------------------------
void print_grid(char **grid, char *delim) {
    printf("\n---print_grid---\n");
    for (int i = 0; grid[i] != NULL; i++) {
        for (int j = 0; grid[i][j] != '\0'; j++) {
            printf("%c%s", grid[i][j], delim);
        }
        printf("\n");
    }
    printf("\n");
}
