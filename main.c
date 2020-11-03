#include "GenericHashTable.h"
#include <stdio.h>
#include <string.h>
int main()
{
    Table *t;
    t = createTable(4, 0, 2);
    int a = 4 ; 
    add(t,&a);
    printTable(t);
}