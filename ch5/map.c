#include <stdio.h>

// Very simple example of using function pointers

int add(int x, int y) {
    printf("x + y: %d\n", x + y);
    return x+y;
}

int sub(int x, int y) {
    printf("x - y: %d\n", x - y);
    return x-y;
}

int divide(int x, int y) {
    printf("x / y: %d\n", x / y);
    return x/y;
}

int map(int (*func)(int , int), int list[]) {
    return func(list[0], list[1]);
}

int main() {
    int l[] = {28, 7};

    printf("map plus: %d\n", map(&add, l));
    printf("map minus: %d\n", map(&sub, l));
    printf("map divide: %d\n", map(&divide, l));
}

