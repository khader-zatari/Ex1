#include "GenericHashTable.h"
#include <stdio.h>
#include <string.h>
int main()
{
    Table *t = createTable(4, 0, 2);
    //printTable(t);
    int a = 12;
    add(t, &a);
    // createTable(4,1,2);
     printTable( t);
    
}