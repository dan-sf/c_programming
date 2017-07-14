#include <stdio.h>

void strncpy(char *s, char *t, int n) {
    for (int i = 0; i < n && *s != '\0'; i++, s++, t++)
        *t = *s;
    *t = '\0';
}

int main() {
    char s[50] = "testing";
    char t[50];
    strncpy(s, t, 10);
    printf("this is s: %s, this is t: %s\n", s, t);
    t[0] =  '\0';
    strncpy(s, t, 3);
    printf("this is s: %s, this is t: %s\n", s, t);
    t[0] =  '\0';
    strncpy(s, t, 2);
    printf("this is s: %s, this is t: %s\n", s, t);
    t[0] =  '\0';
    strncpy(s, t, 1);
    printf("this is s: %s, this is t: %s\n", s, t);
}


