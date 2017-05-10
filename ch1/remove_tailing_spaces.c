#include <stdio.h>

#define MAX 100

int my_getline(char s[], int lim) {
    int c;
    int i;

    for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c!='\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    return i;
}

int main() {
    int count;
    char line[MAX];

    while ((count = my_getline(line, MAX)) > 0) {
        if (count != 1) {
            for (int i = count-1; i >= 0; i--) {
                if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
                    count--;
                }
                else {
                    break;
                }
            }

            for (int i = 0; i < count; i++) {
                printf("%c", line[i]);
            }
            printf("\n");
        }
    }
}

