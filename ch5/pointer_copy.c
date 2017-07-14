#include <stdio.h>

void strcopy(char *a, char *b) {
    // Cryptic minimal way to copy strings using pointers and the fact that
    // strings end with a '\0' (the single equals is key)
    while (*a++ = *b++)
        ;
}

int main() {
    char a[] = "testing";
    char *p = "testing";

    printf("*a: %c\n", *(a+2));
    printf("*p: %c\n", *(++p));
    printf("*p: %c\n", *(++p));

    char b[50];

    strcopy(b, a);
    printf("a: %s\n", a);
    printf("b: %s\n", b);
}

