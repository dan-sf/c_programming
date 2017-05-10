#include <stdio.h>

int main() {
    int c;
    int alfa_count[26];
    for (int i = 0; i < 26; i++)
        alfa_count[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            alfa_count[c-'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("Letter: %c Count: %4d ", i+'a', alfa_count[i]);
        for (int j = 0; j < alfa_count[i]; j++) printf("-");
        printf("\n");
    }
}
