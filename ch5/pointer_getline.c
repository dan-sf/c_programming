#include <stdio.h>
#include <stdlib.h>
# define MAXLINE 1000

void _getline(char *s, int lim) {
    char c;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
}

int main() {
    // Could do this just using the stack but the question calls for more
    // pointers so I am allocating memory on the heap via malloc
    char *line;
    line = malloc(MAXLINE * sizeof(char));
    _getline(line, MAXLINE);
    printf("this is the line: %s", line);
    // Not needed since the os will automatically free memory once the program
    // exits, however, good practice to avoid memory leaks
    free(line); 
}

