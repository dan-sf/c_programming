#include <stdio.h>

#define UPPER 300
#define LOWER 0

int convert_to_celcius(int fahr) {
    return 5 * (fahr - 32) / 9;
}

int main() {
    int cel;
    int lower = LOWER;
    int upper = UPPER;
    int step = 20;

    for (int fahr=lower; fahr <= upper; fahr+=step) {
        cel = convert_to_celcius(fahr);
        printf("%d\t%d\n", fahr, cel);
    }
}

