#include <stdio.h>

int main() {
    int lim = 100;
    char c;
    char s[lim];

    enum loop { NO, YES };
    enum loop okloop = YES;

    // Replacement for the following loop:
    // for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; i++)
    int i = 0;
    while (okloop == YES) {
        if (i >= lim-1) {
            okloop = NO;
        } else if ((c = getchar()) == '\n') {
            s[i] = '\n';
            okloop = NO;
        } else if (c == EOF) {
            okloop = NO;
        } else {
            s[i] = c;
            i++;
        }
    }

    for (int j = 0; j <= i; j++)
        printf("%c", s[j]);
}
