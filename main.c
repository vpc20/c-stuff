#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aoc_tools.h"

char **str_split(char *str, char delim) {
    // Make a copy since strtok modifies the string
    char *str_copy = malloc(strlen(str) + 1);
    if (!str_copy) return NULL;
    strcpy(str_copy, str);

    // Count tokens first
    int count = 0;
    char delim_str[2] = {delim, '\0'};
    char *token = strtok(str_copy, delim_str);
    while (token != NULL) {
        count++;
        token = strtok(NULL, delim_str);
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
    token = strtok(str_copy, delim_str);
    while (token != NULL) {
        str_arr[idx] = malloc(strlen(token) + 1);
        strcpy(str_arr[idx], token);
        idx++;
        token = strtok(NULL, delim_str);
    }

    str_arr[idx] = NULL;
    free(str_copy);
    return str_arr;
}

int main(int argc, char *argv[]) {
    printf("Hello, World!\n");

    char **grid = input_to_grid("/home/vpc/CLionProjects/c-stuff/input.txt");

    // Print the 2D array
    // printf("File contents (%d lines):\n", num_lines);
    printf("------------------------\n");
    for (int i = 0; grid[i] != NULL; i++) {
        printf("Line %d: %s\n", i, grid[i]);
    }

    // Access individual characters
    printf("\n--- Accessing as 2D array ---\n");
    for (int i = 0; grid[i] != NULL; i++) {
        printf("Line %d characters: ", i);
        for (int j = 0; grid[i][j] != '\0'; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    // char *test = "qqq,www,eee,rrr";
    char **str_arr = str_split("qqq,www,eee,rrr", ',');
    for (int i = 0; str_arr[i] != NULL; i++) {
        printf("%d: %s\n", i, str_arr[i]);
    }

    char *substr;
    substring(substr, "qwerasdf", 0, 4);
    printf("%s\n", substr);

    substring(substr, "qwerasdf", 1, 4);
    printf("%s\n", substr);

    substring(substr, "qwerasdf", 2, 4);
    printf("%s\n", substr);

    substring(substr, "qwerasdf", 3, 4);
    printf("%s\n", substr);

    substring(substr, "qwerasdf", 4, 4);
    printf("%s\n", substr);

    substring(substr, "qwerasdf", 5, 4);
    printf("%s\n", substr);

    substring(substr, "qwerasdf", 6, 4);
    printf("%s\n", substr);

    substring(substr, "qwerasdf", 7, 4);
    printf("%s\n", substr);

    substring(substr, "qwerasdf", 8, 4);
    printf("%s\n", substr);

    substring(substr, "qwerasdf", 0, 4);
    printf("%s\n", substr);

    substring(substr, "qwerasdf", 8, 4);
    printf("%s\n", substr);

    substring(substr, "qwerasdf", 0, 4);
    printf("%s\n", substr);

    return 0;
}
