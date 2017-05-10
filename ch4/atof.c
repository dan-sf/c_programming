#include <ctype.h>
#include <stdio.h>

int my_pow(int base, int exp) {
    int output = base;
    for (int i = 1; i < exp; i++)
        output *= base;
    return output;
}

double atof(char s[]) { 
    double val, power;
    int i, sign, sci_power;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if (s[i] == 'e' || s[i] == 'E')
        i++;
    for (sci_power = 0; isdigit(s[i]); i++)
        sci_power = 10 * sci_power + (s[i] - '0');

    if (sci_power > 0)
        val *= my_pow(10, sci_power);

    return sign * val / power;
}

int main() {
    printf("%lf\n", atof("20E2"));
    return 0;
}
