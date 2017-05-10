#include <stdio.h>

int main() {
    int c, count;

    c = getchar();
    count = 0;
    while (c != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') count++;
        c = getchar();
    }
    printf("%d\n", count);
}
