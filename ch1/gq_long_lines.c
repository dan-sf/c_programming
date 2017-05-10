#include <stdio.h>

#define WIDTH 80

int main() {
    char c;
    int char_count = 0;
    while ((c=getchar()) != EOF) {
        char_count++;
        if (c == '\n') {
            printf("\n");
            char_count = 0;
        } else {
            if (char_count >= WIDTH && (c == ' ' || c == '\t' || c == '\n')) {
                printf("\n");
                char_count = 0;
            } else {
                printf("%c", c);
            }
        }
    }
}

