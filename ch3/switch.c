#include <stdio.h>

void escape(char* s, char* t) {
    for (int i = 0, j = 0; s[i] != '\0'; i++, j++) {
        switch (s[i]) {
            case '\t':
                t[j] = '\\'; j++;
                t[j] = 't';
                break;
            case '\n':
                t[j] = '\\'; j++;
                t[j] = 'n';
                break;
            case ' ':
                t[j] = '\\'; j++;
                t[j] = 's';
                break;
            default:
                t[j] = s[i];
                break;
        }
    }
}

void print_string(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
}

int main() {
    char s[] = "te\tsti   ng\ntest";
    char t[sizeof(s)*2];
    escape(s, t);

    print_string(s);
    print_string(t);

}

