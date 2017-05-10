#include <stdio.h>

int main() {
    int c = getchar();
    int b;
    while (c != EOF) {

        b = c!=EOF;
        printf("%d", b);

        if (c == 't') c = 'T';
        putchar(c);
        c = getchar();
    }
    b = c!=EOF;
    printf("\n%d\n", b);
}
