#include <stdio.h>

int mul(int x) {
    return x * x;
}

int main(void)
{
  int c;
  int x;
  int foo;
  int bar;

  // C will evaluate assigment and also return it so statements like
  // while ((c = getchar()) != EOF) can be written
  // You can also write things with the comma operator, C will ignore the
  // return value before the comma then evaluate the next value, returning the
  // last expression computed

  printf("Foo Bar was assigned and tossed out, x is %d\n", (foo = 8, bar = 10, x = 27));
  printf("Vars after assignment: x = %d foo = %d bar = %d\n", x, foo, bar);

  // Example of assigment of p and returning the evaluated expression from a
  // custom function
  int p;
  printf("p is assigned: %d\n", p = mul(10));
  printf("p is still: %d\n", p);

  // The below is equivalent to:
  // while (c = getchar(), != EOF && c != 'x')
  //
  // You need to put c = getchar() in parentheses so that it works with the
  // rest of the boolean expression
  while ((c = getchar()) != EOF && c != 'x')
  {
    switch (c) // This switch demos fall through in case statements
      {
      case '\n':
      case '\r':
        printf (" newline\n");
        break;
      default:
        printf ("%c",c);
      }
  }
  return 0;
}
