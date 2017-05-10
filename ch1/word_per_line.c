#include <stdio.h>

int main() {
    int c = getchar();
    while (c != EOF) {
        if (c == ' ') printf("\n");
        else putchar(c);
        c = getchar();
    }
}
