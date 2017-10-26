#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        switch(*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            case 'c':
                ival = va_arg(ap, int);
                printf("%c", ival);
                break;
            case 'i':
                ival = va_arg(ap, int);
                printf("%i", ival);
                break;
            case '%':
                putchar(*p);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}

int main() {
    minprintf("testing %s, %d, %f\n", "one", 2, 3.0);
    minprintf("testing %c %% %i\n", 'c', 10);
}

