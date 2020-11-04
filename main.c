#include "GenericHashTable.h"
#include <stdio.h>
#include <string.h>
int main()
{
    Table *t;
    t = createTable(4, 1, 2);
    int a = 4;
    int b = 12;
    int c = 16;
    char *p = "abc";
    char *x = "abcd";
    add(t, (char * )p);
     //add(t , (char *) p);
    add(t , x);

     printTable(t);
}