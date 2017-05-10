#include <stdio.h>

#define MAX 1000

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

void reverse(char[] line, count) {
    for (int i = count; i >= 0; i--) {
        if (line[i] != '\n')
            printf("%c", line[i]);
    }
    printf("\n");
}

int main() {
    char c;
    int count;
    char line[MAX];

    while ((count = my_getline(line, MAX)) > 0) {
        reverse(line, count);
    }
}

