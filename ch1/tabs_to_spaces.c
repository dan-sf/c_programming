#include <stdio.h>

#define SPACES 4

int main() {
    char c;
    while ((c=getchar()) != EOF) {
        if (c == '\t') {
            for (int i = 0; i < SPACES; i++) {
                printf(" ");
            }
        } else {
            printf("%c", c);
        }
    }
}

