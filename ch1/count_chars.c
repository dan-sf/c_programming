#include <stdio.h>

int main() {
    int c = getchar();
    int count = 0;
    while (c != EOF) {
        c = getchar();
        if (c != '\n') count++;
    }
    printf("%d\n", count);
}

