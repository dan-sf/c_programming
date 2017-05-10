#include <stdio.h>

int main() {
    int c = getchar();
    int seen_blank = 0;

    while (c != EOF) {
        if (c != ' ') {
            seen_blank = 0;
            putchar(c);
        } else if (!seen_blank) {
            seen_blank = 1;
            putchar(c);
        }

        c = getchar();
    }
}
