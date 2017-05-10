#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, nl, nw, nc, state;
    nl = nw = nc = 0;
    c = getchar();
    while (c != EOF) {
        nc++;
        if (c == '\n') nl++;
        if (c == ' ' || c == '\n' || c == '\t') state = OUT;
        else if (state == OUT) { state = IN; nw++; }
        c = getchar();
    }
    printf("%d %d %d\n", nl, nw, nc);
}
