#include <stdbool.h>
#include <stdio.h>

bool should_remove(char c, char* remove) {
    int i = 0;
    while (remove[i] != '\0')
        if (c == remove[i++])
            return true;
    return false;
}

void squeeze(char* s, char* remove) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++) {
        if (!should_remove(s[i], remove))
            s[j++] = s[i];
    }
    s[j] = '\0';
}

int main() {
    char s[] = "this is a test";
    int i = 0;
    while (s[i] != '\0')
        printf("%c", s[i++]);
    printf("\n");

    squeeze(s, "th");
    i = 0;
    while (s[i] != '\0')
        printf("%c", s[i++]);
    printf("\n");
    return 0;
}

