#include <stdio.h>

void strncat(char *s, char *t, int n) {
    for ( ; *s != '\0'; s++)
        ;
    for (int i = 0; *t != '\0' && i < n; i++, t++, s++)
        *s = *t;
    *s = '\0';
}

void print_out(char *a, char *b, int n) {
    printf("this is var one: %s, this is var two: %s\n", a, b);
    strncat(a, b, n);
    printf("this is a strncat: %s\n", a);
}

int main() {
    char s[50] = "testing";
    char t[50] = "123";
    print_out(s, t, 5);
    char a[50] = "testing";
    char b[50] = "123";
    print_out(a, b, 2);
    char c[50] = "testing";
    char d[50] = "123";
    print_out(c, d, 1);
}



