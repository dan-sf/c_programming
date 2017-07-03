#include <stdio.h>
#include <string.h>
#define swap(t, x, y) t temp = (x); (x) = (y); (y) = temp

void _reverse(char s[], int i, int l) {
    if (i == (l / 2))
        return;
    else {
        swap(char, s[i], s[l - 1 - i]);
        _reverse(s, i + 1, l);
    }
}

void reverse(char s[]) {
    int l = strlen(s);
    int i = 0;
    _reverse(s, i, l);
}

int main() {
    char s[] = "testing";
    reverse(s);
    printf("%s\n", s);
}

