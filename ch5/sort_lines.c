#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char *linemem);
void writelines(char*lineptr[], int nlines);
void _qsort(char *lineptr[], int left, int right);

int main() {
    int nlines;
    char lm[MAXLEN];
    if ((nlines = readlines(lineptr, MAXLINES, lm)) >= 0) {
        _qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int _getline(char *s, int lim) {
    int i;
    char c;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
        *s++ = c;
        i++;
    }
    if (c == '\n') {
        *s++ = c;
        i++;
    }
    *s = '\0';
    return i;
}

int readlines(char *lineptr[], int maxlines, char *linemem) {
    int len, nlines;
    char line[MAXLEN];
    char *p = linemem;

    nlines = 0;
    while ((len = _getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p+len > linemem+MAXLEN))
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

void _qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    _qsort(v, left, last-1);
    _qsort(v, last+1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

