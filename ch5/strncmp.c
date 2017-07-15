#include <stdio.h>

int strncmp(char *s, char *t, int n) {
    for (int i = 0; i < n && *s != '\0'; i++, s++, t++) {
        if (*s < *t)
            return -1;
        else if (*s > *t)
            return 1;
    }
    return 0;
}

int main() {
    char *s = "testing";
    char *t = "testing";
    printf("this is s: %s, this is t: %s, this is cmp: %d\n", s, t, strncmp(s,t,10));
    s = "testing";
    t = "tes";
    printf("this is s: %s, this is t: %s, this is cmp: %d\n", s, t, strncmp(s,t,10));
    s = "bar";
    t = "baz";
    printf("this is s: %s, this is t: %s, this is cmp: %d\n", s, t, strncmp(s,t,2));
    s = "bar";
    t = "baz";
    printf("this is s: %s, this is t: %s, this is cmp: %d\n", s, t, strncmp(s,t,3));
    s = "foo";
    t = "foobar";
    printf("this is s: %s, this is t: %s, this is cmp: %d\n", s, t, strncmp(s,t,3));
}

