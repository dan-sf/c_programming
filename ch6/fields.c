#include <stdio.h>

int main() {
    //unsigned int c : 1;
    int c = 0;

    struct {
        unsigned int t : 2;
    } flag;

    for (int i = 0; i < 10; i++) {
        //printf("this is c: %d\n", c);
        //c++;
        printf("this is t: %d\n", flag.t);
        flag.t++;
    }
}
