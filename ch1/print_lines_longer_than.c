#include <stdio.h>

#define LIMIT 10
#define MAX 1000

int main() {
    char c;
    int count = 0;
    char current_line[MAX];

    while ((c=getchar()) != EOF) {
        count++;
        if (c != '\n') { 
            current_line[count-1] = c;
        } else {
            if (count >= LIMIT) {
                for (int i = 0; i < count; i++) {
                    printf("%c", current_line[i]);
                }
                printf("\n");
            }
            count = 0;
        }
    }
}

