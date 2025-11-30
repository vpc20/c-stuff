#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tools.h"

#define INITIAL_CAPACITY 10
// #define INITIAL_LINE_SIZE 128
//
// // Function to read a line of arbitrary length
// char* read_line(FILE *file) {
//     size_t capacity = INITIAL_LINE_SIZE;
//     size_t len = 0;
//     char *line = (char *)malloc(capacity * sizeof(char));
//
//     if (line == NULL) {
//         return NULL;
//     }
//
//     int c;
//     while ((c = fgetc(file)) != EOF && c != '\n') {
//         // Grow buffer if needed
//         if (len + 1 >= capacity) {
//             capacity *= 2;
//             char *temp = (char *)realloc(line, capacity * sizeof(char));
//             if (temp == NULL) {
//                 free(line);
//                 return NULL;
//             }
//             line = temp;
//         }
//         line[len++] = c;
//     }
//
//     // If we read nothing and hit EOF, return NULL
//     if (len == 0 && c == EOF) {
//         free(line);
//         return NULL;
//     }
//
//     line[len] = '\0';
//     return line;
// }

int readtxt() {
    char **lines = NULL;
    int num_lines = 0;
    int capacity = INITIAL_CAPACITY;

    // Open file
    FILE *file = fopen("/home/vpc/CLionProjects/c-stuff/input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    // Allocate initial array
    lines = (char **) malloc(capacity * sizeof(char *));
    if (lines == NULL) {
        printf("Error: Memory allocation failed\n");
        fclose(file);
        return 1;
    }

    // Read file line by line
    char *line;
    while ((line = read_line(file)) != NULL) {
        // Grow array if needed
        if (num_lines >= capacity) {
            capacity *= 2;
            char **temp = (char **) realloc(lines, capacity * sizeof(char *));
            if (temp == NULL) {
                printf("Error: Memory reallocation failed\n");
                free(line);
                for (int i = 0; i < num_lines; i++) {
                    free(lines[i]);
                }
                free(lines);
                fclose(file);
                return 1;
            }
            lines = temp;
        }

        lines[num_lines] = line;
        num_lines++;
    }

    fclose(file);

    // Print the 2D array
    printf("File contents (%d lines):\n", num_lines);
    printf("------------------------\n");
    for (int i = 0; i < num_lines; i++) {
        printf("Line %d: %s\n", i, lines[i]);
    }

    // Access individual characters
    printf("\n--- Accessing as 2D array ---\n");
    for (int i = 0; i < num_lines; i++) {
        printf("Line %d characters: ", i);
        for (int j = 0; lines[i][j] != '\0'; j++) {
            printf("%c ", lines[i][j]);
        }
        printf("\n");
    }

    // Free all allocated memory
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}

// return lines and num_lines_out in parameter
// int readtxt(const char *filename, char ***lines_out, int *num_lines_out) {
//     char **lines = NULL;
//     int num_lines = 0;
//     int capacity = INITIAL_CAPACITY;
//
//     // Open file
//     FILE *file = fopen(filename, "r");
//     if (file == NULL) {
//         printf("Error: Could not open file\n");
//         return 1;
//     }
//
//     // Allocate initial array
//     lines = (char **)malloc(capacity * sizeof(char *));
//     if (lines == NULL) {
//         printf("Error: Memory allocation failed\n");
//         fclose(file);
//         return 1;
//     }
//
//     // Read file line by line
//     char *line;
//     while ((line = read_line(file)) != NULL) {
//         // Grow array if needed
//         if (num_lines >= capacity) {
//             capacity *= 2;
//             char **temp = (char **)realloc(lines, capacity * sizeof(char *));
//             if (temp == NULL) {
//                 printf("Error: Memory reallocation failed\n");
//                 free(line);
//                 for (int i = 0; i < num_lines; i++) {
//                     free(lines[i]);
//                 }
//                 free(lines);
//                 fclose(file);
//                 return 1;
//             }
//             lines = temp;
//         }
//         lines[num_lines] = line;
//         num_lines++;
//     }
//     fclose(file);
//
//     // Return the array and count to caller
//     *lines_out = lines;
//     *num_lines_out = num_lines;
//
//     return 0;  // Success
// }
