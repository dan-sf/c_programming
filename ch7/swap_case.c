#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char c;

    char *description = "This program will convert text read from stdin to either lowercase or uppercase";
    char *usage = "Usage: echo TEST | ./swap_case [u|l]";

    if (strcmp(argv[1], "l") == 0) {
        while ((c = getchar()) != EOF)
            putchar(tolower(c));
    } else if (strcmp(argv[1], "u") == 0) {
        while ((c = getchar()) != EOF)
            putchar(toupper(c));
    } else {
        printf("Error invalid command line args!\n\n");
        printf("%s\n", description);
        printf("%s\n\n", usage);
    }
}

