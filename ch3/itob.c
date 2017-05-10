#include <stdio.h>
#include <string.h>

void reverse(char* s) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itob(int n, char s[], int b) {
    int i, j, sign;

    if ((sign = n) < 0)
        n = -n;

    i = 0;
    do {
        j = n % b;
        s[i++] = (j <= 9) ? j+'0' : j+'a'-10;
    } while ((n /= b) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[100];

    itob(5026, s, 16);

    char c;
    for (int i = 0; (c = s[i]) != '\0'; i++) {
        printf("%c", s[i]);
    } printf("\n");
}


