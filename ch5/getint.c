#include <ctype.h>
#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if(bufp >= BUFSIZE)
        printf("ungetch: too many chars\n");
    else
        buf[bufp++] = c;
}

int getint(int *pn) {
    int c, check_sign, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        check_sign = c;
        if (!isdigit(c = getch())) {
            if (c != EOF) ungetch(c);
            ungetch(check_sign);
            return check_sign;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main() {
    int n = -1;
    int k;
    k = getint(&n);

    if (n == -1 || k == '-' || k == '+')
        printf("Error: invalid integer read\n");
    else
        printf("this is n: %d, this is k: %c\n", n, k);
}

