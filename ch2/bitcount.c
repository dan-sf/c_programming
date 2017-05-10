#include <stdio.h>

int bitcount(unsigned x) {
    int b = 0;
    while (x != 0) {
        if (x & 1)
            b++;
        x >>= 1;
    }
    return b;
}

int main() {
    printf("num bits: %d\n", bitcount(255));
}
