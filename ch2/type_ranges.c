#include <stdio.h>
#include <limits.h>


int main() {
    // Using bit manipulation
    printf("bit manip:\n");

    // Signed ranges
    printf("signed char: min = %d, max = %d\n",
           -(char)((unsigned char) ~0 >> 1),
            (char)((unsigned char) ~0 >> 1));
    printf("signed short: min = %d, max = %d\n",
           -(short)((unsigned short) ~0 >> 1),
            (short)((unsigned short) ~0 >> 1));
    printf("signed int: min = %d, max = %d\n",
           -(int)((unsigned int) ~0 >> 1),
            (int)((unsigned int) ~0 >> 1));
    printf("signed long: min = %ld, max = %ld\n",
           -(long)((unsigned long) ~0 >> 1),
            (long)((unsigned long) ~0 >> 1));
    // Unsigned ranges
    printf("unsigned char: min = %u, max = %u\n", 0,
            (unsigned char) ~0);
    printf("unsigned short: min = %u, max = %u\n", 0,
            (unsigned short) ~0);
    printf("unsigned int: min = %u, max = %u\n", 0,
            (unsigned int) ~0);
    printf("unsigned long: min = %u, max = %lu\n\n", 0,
            (unsigned long) ~0);

    // Using the limits header
    printf("limits.h:\n");

    // Signed ranges
    printf("signed char: min = %d, max = %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("signed short: min = %d, max = %d\n", SHRT_MIN, SHRT_MAX);
    printf("signed int: min = %d, max = %d\n", INT_MIN, INT_MAX);
    printf("signed long: min = %ld, max = %ld\n", LONG_MIN, LONG_MAX);
    // Unsigned ranges
    printf("unsigned char: min = %u, max = %u\n", 0, UCHAR_MAX);
    printf("unsigned short: min = %u, max = %u\n", 0, USHRT_MAX);
    printf("unsigned int: min = %u, max = %u\n", 0, UINT_MAX);
    printf("unsigned long: min = %u, max = %lu\n", 0, ULONG_MAX);

}
