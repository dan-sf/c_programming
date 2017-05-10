#include <stdio.h>

#define MAX 100

void expand(char* s1, char* s2) {
    for (int i = 0, j = 0; s1[i] != '\0'; i++, j++){
        if (s1[i] == '-') {
            if (s1[i-1] >= 'a' && s1[i-1] <= 'z' && s1[i+1] >= 'a' && s1[i+1] <= 'z') {
                for (int start = s1[i-1], end = s1[i+1]; start < end; start++) {
                    s2[j] = start + 1;
                    j++;
                }
                j--; i++;
            } else if (s1[i-1] >= 'A' && s1[i-1] <= 'Z' && s1[i+1] >= 'A' && s1[i+1] <= 'Z') {
                for (int start = s1[i-1], end = s1[i+1]; start < end; start++) {
                    s2[j] = start + 1;
                    j++;
                }
                j--; i++;
            } else if (s1[i-1] >= '0' && s1[i-1] <= '9' && s1[i+1] >= '0' && s1[i+1] <= '9') {
                for (int start = s1[i-1], end = s1[i+1]; start < end; start++) {
                    s2[j] = start + 1;
                    j++;
                }
                j--; i++;
            }
        } else {
            s2[j] = s1[i];
        }
    }
}

int main() {
    //
    char s1[] = "this is a test a-z 5-9 m-q";
    char sX[] = "this is a test";
    char s2[MAX];
    expand(s1, s2);
    for (int i = 0; s2[i] != '\0'; i++)
        printf("%c", s2[i]);
    printf("\n");
}

