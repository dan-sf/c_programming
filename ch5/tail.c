#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 100

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

int main(int argc, char *argv[]) {
    int nlines_output;
    int nlines_read = 0;

    // Parse number of lines to output, default 10
    if (*++argv && (*argv)[0] == '-') {
        ++(*argv);
        nlines_output = atoi(*argv);
    } else {
        nlines_output = 10;
    }

    // Create array of pointers and initalize it to null
    char *line_array[nlines_output];
    for (int i = 0; i < nlines_output; i++) {
        line_array[i] = NULL;
    }

    // Create a buffer and allocate space
    char* buf;
    char* bufend;
    buf = malloc(nlines_output * MAXLINE);
    bufend = buf + nlines_output * MAXLINE;

    char *p;
    p = buf;

    int len;
    char line[MAXLINE];
    int last = 0;

    while ((len = _getline(line, MAXLINE)) > 0) {
        if (p + len + 1 >= bufend) // if buffer wrapped
            p = buf;

        line_array[last] = p;
        strcpy(line_array[last], line);

        if (++last >= MAXLINE)
            last = 0;
        p += len + 1;
        nlines_read++;
    }

    if (nlines_output > nlines_read)
        nlines_output = nlines_read;

    int first = last - nlines_output;

    if (first < 0)
        first += MAXLINE;

    for (int i = first; nlines_output-- > 0; i = (i + 1) % MAXLINE)
        printf("%s", line_array[i]);

    return 0;
}

