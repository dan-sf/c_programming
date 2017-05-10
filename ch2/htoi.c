#include <stdio.h>
#include <ctype.h>
#include <string.h>

void lower_string(char *s) {
    int i = 0;
    while (s[i]) {
        s[i] = tolower(s[i]);
        i++;
    }
}

int my_pow(int x, int y) {
    int output = 1;
    if (y <= 0) return output;

    for (int i = 0; i < y; i++) {
        output *= x;
    }
    return output;
}

int htoi(char s[]) {
    int i, j;
    int output = 0;
    lower_string(s);

    if (s[0] == '0' && s[1] == 'x')
        i = 2;
    else
        i = 0;

    // Set j to the end of the string
    j = strlen(s) - 1;
    int value;
    int count = 0;

    // Loop through the string backwards
    while (j >= i) {
        // Convert the chars to ints
        if (s[j] >= '0' && s[j] <= '9')
            value = s[j] - '0';
        else if (s[j] >= 'a' && s[j] <= 'f')
            value = s[j] - 'a' + 10;

        output += my_pow(16, count) * value;
        j--;
        count++;
    }

    return output;
}

int main() {
    char x[] = "0x12b";
    int output = htoi(x);
    for (int i = 0; i < sizeof(x); i++) {
        printf("%c", x[i]);
    }
    printf("\n");
    printf("%d\n", output);
}

