#include <stdio.h>

#define UPPER 300
#define LOWER 0

int main() {
    //int fahr, cel;
    int cel;
    //int lower, upper, step;

    int lower = LOWER;
    int upper = UPPER;
    int step = 20;

    //fahr = lower;
    //while (fahr <= upper) {
    for (int fahr=upper; fahr >= lower; fahr-=step) {
        cel = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, cel);
        //fahr += step;
    }
}
