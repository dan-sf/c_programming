#include <stdio.h>

#define square1(x) x*x
#define square2(x) (x*x)
#define square3(x) (x)*(x)
#define square4(x) ((x)*(x))

int main() {
#if 0
    // ans1: 12.000000, ans2: 3.600000, ans3: 18.000000, ans4: 2.000000
    double ans1 = 18.0/square1(2+1);
    double ans2 = 18.0/square2(2+1);
    double ans3 = 18.0/square3(2+1);
    double ans4 = 18.0/square4(2+1);
#else
    // ans1: 5.000000, ans2: 5.000000, ans3: 9.000000, ans4: 9.000000
    double ans1 = square1(2+1);
    double ans2 = square2(2+1);
    double ans3 = square3(2+1);
    double ans4 = square4(2+1);
#endif
    printf("ans1: %f, ans2: %f, ans3: %f, ans4: %f\n", ans1, ans2, ans3, ans4);
    return 0;
}

