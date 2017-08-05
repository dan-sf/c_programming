#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100

void push(double);
double pop(void);
double peek(void);

int main(int argc, char *argv[]) {
    int type;
    double op1;
    double op2;
    char *s;

    while (s = *(++argv)) {
        type = *s;
        if (type >= '0' && type <= '9')
            push(atof(s));
        else if (type == '+')
            push(pop() + pop());
        else if (type == '*')
            push(pop() * pop());
        else if (type == '-') {
            op2 = pop();
            push(pop() - op2);
        }
        else if (type == '/') {
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
        }
        else if (type == '%') {
            op2 = pop();
            if (op2 != 0.0)
                push((int)pop() % (int)op2);
            else
                printf("error: zero divisor\n");
        }
        else
            printf("error: unknown command %s\n", s);
    }
    printf("Results: %f\n", pop());

    return 0;
}

// Stack

#define MAXVAL 100

int sp = 0;
double stack[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        stack[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return stack[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double peek(void) {
    if (sp > 0)
        return stack[sp - 1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

