#include "GenericHashTable.h"
#include <stdio.h>
#include <string.h>
int main()
{
  Table *t;
  t = createTable(4, 0, 6);
  int a = 4;
  int b = 12;
  int c = 16;
  char *p = "abc";
  char *x = "abcd";
  char *z = "abc";
  //add(t , (char *) p);
  add(t, &a); //
  add(t, &b); //
  add(t, &b); //0
  add(t, &c); //01
  add(t, &c); //012
  add(t, &c); //0123

  //printTable(t);
  int y = 4;
  //printf("hello");
  //search(t, z);
  // printf("%s", (char *)search(t, z)->next->data);
}