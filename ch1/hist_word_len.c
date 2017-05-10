#include <stdio.h>

int main() {
    int c, nc;
    int word_count[15];
    for (int i = 0; i < 15; i++)
        word_count[i] = 0;

    nc = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            word_count[nc]++;
            nc = 0;
        }
        else {
            nc++;
        }
    }

    for (int i = 1; i < 15; i++) {
        printf("Word length: %4d Word count: %4d ", i, word_count[i]);
        for (int j = 0; j < word_count[i]; j++) printf("-");
        printf("\n");
    }
}
