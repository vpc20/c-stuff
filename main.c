#include <stdio.h>
#include "aoc_tools.h"
// #include "read_text.c"

int main(int argc, char *argv[]) {
    printf("Hello, World!\n");

    char **grid;
    grid = input_to_grid("/home/vpc/CLionProjects/c-stuff/input.txt");

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

    return 0;
}
