#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int nflag;

    if (*++argv && !strcmp(*argv, "-n")) {
        ++argv;
        nflag = 0;
    }
    else {
        nflag = 1;
    }

    while (*argv) {
        printf("%s", *argv);
        if (*++argv)
            printf(" ");
    }
    if (nflag) {
        printf("\n");
    }

    return 0;
}

