#include <stdio.h>

#define SPACES 4

int main() {
    char c;
    int space_count = 0;
    while ((c=getchar()) != EOF) {
        if (c == ' ') {
            space_count++;
            if (space_count == SPACES) {
                printf("\t");
                space_count = 0;
            }
        } else {
            for (int i = 0; i < space_count; i++) {
                printf(" ");
            }
            space_count = 0;
            printf("%c", c);
        }
    }
}


