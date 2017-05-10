#include <stdio.h>

int main() {
    typedef enum testing { ONE, TWO, THREE } boo;
    boo t = TWO;

    printf("testing enum: %d\n", t);
}
