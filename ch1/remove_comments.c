#include <stdio.h>
#include <stdbool.h>

int main() {
    char c, last_c;
    bool comment = false;
    bool first = true;

    // loop through chars
    while ((c=getchar()) != EOF) {
        if (!first) {
            if (last_c == '/' && c == '/') {
                comment = true;
            }
            if (!comment) {
                printf("%c", last_c);
            }
            if (last_c == '\n') {
                printf("\n");
                comment = false;
            }
        }
        first = false;
        last_c = c;
    }
    printf("%c", last_c);
}

