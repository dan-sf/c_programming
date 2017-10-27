#include <stdio.h>
#include <stdarg.h>

void minscanf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int *ival;
    double *dval;
    char fmtstr[100];

    int i = 0;
    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            fmtstr[i++] = *p;
            continue;
        }

        fmtstr[i++] = '%';
        while(*(p+1) && !isalpha(*(p+1)))
            fmtstr[i++] = *++p;
        fmtstr[i++] = *(p+1);
        fmtstr[i++] = '\0';

        switch(*++p) {
            case 'd':
                ival = va_arg(ap, int *);
                scanf(fmtstr, ival);
                break;
            case 'f':
                dval = va_arg(ap, double *);
                scanf(fmtstr, dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                scanf(fmtstr, sval);
                break;
            case 'c':
                ival = va_arg(ap, int);
                scanf(fmtstr, ival);
                break;
            case 'i':
                ival = va_arg(ap, int);
                scanf(fmtstr, ival);
                break;
            case '%':
                scanf(fmtstr);
                break;
            default:
                scanf(fmtstr);
                break;
        }
    }
    va_end(ap);
}

int main() {
    int i;
    minscanf("test %d", &i);
    printf("this is i: %d\n", i);
}

