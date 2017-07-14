#include <stdio.h>

void strcat(char *s, char *t) {
    for ( ; *s != '\0'; s++)
        ;
    for ( ; *t != '\0'; t++, s++)
        *s = *t;
    *s = '\0';
}

int main() {
    char s[50] = "testing";
    char t[50] = "123";
    printf("this is s: %s, this is t: %s\n", s, t);
    strcat(s, t);
    printf("this is a strcat: %s\n", s);
}

