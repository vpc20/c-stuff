#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aoc_tools.h"
#include "tools.h"

// -------------------------------------------------------------------------------
char *str_add(char str1[]) {

    char str2[] = "added string";
    char *str3 = (char *) malloc(1000 * sizeof(char));
    strcat(str1, str2);
    strcpy(str3, str1);
    return str3;

}

int main(int argc, char *argv[]) {
    printf("Hello, World!\n");

    //-------------------------------------------------------------------------
    char **grid = input_to_grid("/home/vpc/CLionProjects/c-stuff/input.txt");
    print_grid(grid, " ");

    //-------------------------------------------------------------------------
    // Single character delimiter
    char **parts = str_split("apple,banana,cherry", ",");
    for (int i = 0; parts[i] != NULL; i++) {
        printf("%s\n", parts[i]);
    }
    free(parts);

    // // Multi-character delimiter
    // parts = str_split("apple::banana::cherry", "::");
    // for (int i = 0; parts[i] != NULL; i++) {
    //     printf("%s\n", parts[i]);
    // }
    // free(parts);
    //
    // // Multiple delimiter characters (splits on ANY of them)
    // parts = str_split("apple,banana;cherry", ",;");
    // for (int i = 0; parts[i] != NULL; i++) {
    //     printf("%s\n", parts[i]);
    // }
    // free(parts);
    //
    // // Whitespace delimiters
    // parts = str_split("apple banana\tcherry", " \t");
    // for (int i = 0; parts[i] != NULL; i++) {
    //     printf("%s\n", parts[i]);
    // }
    // free(parts);
    //
    // printf("last one\n");
    // // Whitespace delimiters
    // parts = str_split("apple,banana;cherry,;grapes", ",;");
    // for (int i = 0; parts[i] != NULL; i++) {
    //     printf("%s\n", parts[i]);
    // }
    // free(parts);

    //-------------------------------------------------------------------------
    // char *substr;
    // substring(substr, "qwerasdf", 0, 4);
    // printf("%s\n", substr);
    //
    // substring(substr, "qwerasdf", 1, 4);
    // printf("%s\n", substr);
    //
    // substring(substr, "qwerasdf", 2, 4);
    // printf("%s\n", substr);
    //
    // substring(substr, "qwerasdf", 3, 4);
    // printf("%s\n", substr);
    //
    // substring(substr, "qwerasdf", 4, 4);
    // printf("%s\n", substr);
    //
    // substring(substr, "qwerasdf", 5, 4);
    // printf("%s\n", substr);
    //
    // substring(substr, "qwerasdf", 6, 4);
    // printf("%s\n", substr);
    //
    // substring(substr, "qwerasdf", 7, 4);
    // printf("%s\n", substr);
    //
    // substring(substr, "qwerasdf", 8, 4);
    // printf("%s\n", substr);
    //
    // substring(substr, "qwerasdf", 0, 4);
    // printf("%s\n", substr);
    //
    // substring(substr, "qwerasdf", 8, 4);
    // printf("%s\n", substr);
    //
    // substring(substr, "qwerasdf", 0, 4);
    // printf("%s\n", substr);

    //-------------------------------------------------------------------------
    // you can use strcpy to copy char *s to char s1[] before trimming
    char s1[] = "  asdf   ";
    ltrim(s1);
    printf("ltrim '%s'\n", s1);

    // char *s2 = "  asdf   ";
    // s2 = ltrim(s2);
    // printf("ltrim '%s'\n", s2);

    char s3[] = "  asdf   ";
    rtrim(s3);
    printf("rtrim '%s'\n", s3);

    char s5[] = "  asdf   ";
    trim(s5);
    printf("trim '%s'\n", s5);


    // char s6[] = "test str_add";
    // char s7[] = "";
    // // char *s7;
    // strcpy(s7, str_add(s6));
    // printf("%s\n", s7);

    return 0;
}
