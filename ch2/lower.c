#include <stdio.h>

void lower(char* s) {
    int i = 0;
    while (s[i] != '\0') {
        s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? (s[i] - 'A' + 'a') : s[i];
        i++;
    }
}

int main() {
    char s[] = "This Is a tEsT";
    lower(s);
    for (int i = 0; s[i] != '\0'; i++)
        printf("%c", s[i]);
    printf("\n");
}
