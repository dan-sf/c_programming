#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100

int main() {
    int type;
    double op1;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;

            // Added command functions

            case 'c':
                clear();
                break;
            case 'd':
                duplicate_top();
                break;
            case 's':
                swap_top();
                break;
            case 'p':
                printf("\t%.8g\n", peek());
                break;
            case 'S':
                push(sin(pop()));
                break;
            case 'P':
                op1 = pop();
                push(pow(pop(), op1));
                break;
            case 'E':
                push(exp(pop()));
                break;

            // End exec and handle defaults
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}

