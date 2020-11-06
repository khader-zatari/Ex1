#include "GenericHashTable.h"
#include <stdio.h>
#include <string.h>
int main()
{
  Table *t;
  t = createTable(5, 0, 3);
  int a = 5;
  int b = 10;
  int c = 15;
  int d = 20;
  int e = 25;
  int f = 30;
  int g = 35;
  int h = 40;
  int i = 45;
  int j = 50;
  int k = 55; 
  int l = 60; 
  int m = 65;
  int w = 4; 

  char *p = "abc";
  char *x = "abcd";
  char *z = "abc";
  //add(t , (char *) p);
  // add(t, &a); //iShouldDoubleIt
  // printf("%d",add(t, &a)); //
 


  add(t, &a); //0
  add(t, &b); //01
  add(t, &c); //012
//   add(t, &d); //0123
//   add(t, &e);
//   add(t, &f);
//   add(t, &g);
//   add(t, &h);
//   add(t, &i);
//   add(t, &j);
//    add(t, &k);
//   add(t, &l);
//     add(t, &w);
//      add(t, &w); add(t, &w); add(t, &w); add(t, &w); add(t, &w); add(t, &w); add(t, &w); add(t, &w);
//  add(t, &w); add(t, &w); add(t, &w); add(t, &w);

 // add(t, &m);
  //   add(t, &b); //iShouldDoubleIt
  // add(t, &b); //
  // add(t, &b); //0
  // add(t, &c); //01
  // add(t, &c); //012
  // add(t, &c); //0123
  //add(t, &b);
  //add(t, &e);

  printTable(t);
  int y = 4;
  //printf("hello");
  //search(t, z);
  // printf("%s", (char *)search(t, z)->next->data);
}