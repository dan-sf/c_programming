#include <stdbool.h>
#include <stdio.h>

bool is_there(char c, char* any_string) {
    int i = 0;

    while (any_string[i] != '\0')
        if (c == any_string[i++])
            return true;
    return false;
}

int any(char* s, char* any_string) {
    int i = 0;

    while (s[i] != '\0') {
        if (is_there(s[i], any_string))
            return i;
        i++;
    }
    return -1;
}

int main() {
    char s[] = "this is a test";
    char a[] = "as";
    int i = 0;
    while (s[i] != '\0')
        printf("%c", s[i++]);
    printf("\n");

    int x = any(s, a);
    printf("%d\n", x);

    return 0;
}

