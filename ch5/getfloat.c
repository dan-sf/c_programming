#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int tens(int zeros) {
    int output = 1;
    for (int i = 0; i < zeros; i++)
        output *= 10;
    return output;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if(bufp >= BUFSIZE)
        printf("ungetch: too many chars\n");
    else
        buf[bufp++] = c;
}

float getfloat(int *pn) {
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

    bool seen_float = false;
    int float_count = 0;
    for (*pn = 0; isdigit(c) || c == '.'; c = getch()) {
        if (c == '.') {
            if (seen_float)
                return -1;
            else
                seen_float = true;
        } else {
            *pn = 10 * *pn + (c - '0');
            if (seen_float) float_count++;
        }
    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    if (seen_float) {
        return (float)(*pn) / (float)tens(float_count);
    } else {
        return (float)(*pn);
    }
}

int main() {
    int n = -1;
    float k;
    k = getfloat(&n);

    if (n == -1 || k == '-' || k == '+')
        printf("Error: invalid float read\n");
    else
        printf("this is n: %d, this is k: %f\n", n, k);
}

