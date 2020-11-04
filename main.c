#include "GenericHashTable.h"
#include <stdio.h>
#include <string.h>
int main()
{
    Table *t;
    t = createTable(4, 0, 3);
    int a = 4;
    int b = 12;
    int c = 16;
     char const *p = "abc";
    add(t, &p);
    // add(t , &b);
    // add(t , &c);
  
    printTable(t);
}