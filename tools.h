#ifndef C_STUFF_TOOLS_H
#define C_STUFF_TOOLS_H


// Function declarations
void substring(char *dest, const char *src, int start, int length);
char *ltrim(char *s);
char *rtrim(char *s);
char *trim(char *s);
char **str_split(const char *str, const char *delim);
char *read_line(FILE *file);
void print_grid(char **grid, char *delim);

// Constant definitions
#define MAX_TEXT_LEN 128


#endif //C_STUFF_TOOLS_H