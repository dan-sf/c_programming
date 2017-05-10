#include <stdio.h>
#include <stdint.h>

typedef uint8_t uint8;
typedef uint16_t uint16;

// Helper function to print out binary strings for debugging
void bstring(uint8 x) {
    char output[8];
    for (uint8 i = 0; i < 8; i++) {
        if ((1 << i) & x)
            output[i] = 1;
        else
            output[i] = 0;
    }

    int t = 8;
    for (uint8 j = 0; j < 8; j++) {
        printf("%d", output[--t]);
    }
    printf("\n");
}

uint8 invert(uint8 x, uint8 p, uint8 n) {
    // Invert (1->0 and 0->1) x's n bits that begin at p
    uint8 n_ones = ~(~0 << n);
    uint8 output = x ^ (n_ones<<p);

    return output;
}

int main() {
    uint8 x = 0xFF;
    uint8 p = 2;
    uint8 n = 3;
    uint8 output = invert(x,p,n);
    bstring(output);
}

