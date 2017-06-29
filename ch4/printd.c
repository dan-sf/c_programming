#include <stdio.h>
#include <stdlib.h>

void printd(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}

void strd(int n, char s[]) {
    static int i;

    if (n / 10) {
        strd(n / 10, s);
    } else {
        i = 0;
        if (n < 0) s[i++] = '-';
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}

int main() {
    printd(123);
    printf("\n");

    char s[10] = "";
    strd(123, s);
    printf("%s\n", s);
}

