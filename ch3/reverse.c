#include <stdio.h>
#include <string.h>

// Reverse a string inplace (making use of the comma operator)
void reverse(char* s) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main() {
    char s[] = "testing";
    reverse(s);
    for (int i = 0; s[i] != '\0'; i++) {
        printf("%c", s[i]);
    } printf("\n");
}
