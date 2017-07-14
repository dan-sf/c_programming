#include <stdio.h>

int strend(char *s, char *t) {
    // strend returns 1 if t matches the end of s, 0 otherwise

    int i;
    for (i = 0; *t != '\0'; t++, i++)
        ;
    for ( ; *s != '\0'; s++)
        ;
    s -= i;
    t -= i;

    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 1;

    return 0;
}

void print_out(char *s, char *t) {
    printf("this is var one: '%s', this is var two: '%s', this is strend (1 if end matches else 0): '%d'\n", s, t, strend(s, t));
}

int main() {
    char *s = "testing";
    char *t = "ing";
    print_out(s, t);
    char *a = "123";
    char *b = "3";
    print_out(a, b);
    char *c = "foo";
    char *d = "bar";
    print_out(c, d);
}

