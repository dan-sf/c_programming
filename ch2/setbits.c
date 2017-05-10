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

uint8 setbits(uint8 x, uint8 p, uint8 n, uint8 y) {
    // Set x's n bits that begin at p to the rightmost n bits of y
    // Note: 0xff could be written as ~0
    uint8 y_n_right_most_bits = (~(0xff << n)) & y;
    y_n_right_most_bits = y_n_right_most_bits | (0xff << n);
    y_n_right_most_bits = (y_n_right_most_bits<<p) | (1<<p)-1;
    uint8 output = y_n_right_most_bits & x;

    return output;
}

int main() {
    uint8 x = 0xFF;
    uint8 p = 0;
    uint8 n = 4;
    uint8 y = 0xA;
    uint8 output = setbits(x,p,n,y);
    bstring(output);
}
