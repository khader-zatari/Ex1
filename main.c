#include "GenericHashTable.h"
#include <stdio.h>
#include <string.h>
int main()
{



    // Table* table = createTable(5, STR_TYPE, 2);
    // char data[] = "he";
    // char data1[] = "hi";
    // char data2[] = "hello";
    // char data3[] = "Mustafa";
    // char data4[] = "d";
    // char data5[] = "i";
    // char data6[] = "f";
    // char data7[] = "zz";
    // add(table, data);
    // add(table, data1);
    // add(table, data2);
    // add(table, data3);
    // add(table, data4);
    // add(table, data5);
    // add(table, data6);
    // Object* result = search(table, data);
    // printf("%s\n", (char*)result->data);
    // result = search(table, data2);
    // printTable(table);
    // printf("%s\n", (char*)result->data);
    // result = search(table, data1);
    // printf("%s\n", (char*)result->data);
    //  result = search(table, data3);
    //  printf("%s\n", (char*)result->data);
    //  result = search(table, data4);
    // if (result != NULL){
    // printf("%s\n", (char*)result->data);
    // }
    // result = search(table, data7);
    // if(result == NULL){
    //     printf("sucsses\n");
    // }
    // printTable(table);
    // printf("\n\n");
    // removeObj(table, data);
    // removeObj(table, data2);
    // removeObj(table, data3);
    // removeObj(table, data4);
    // removeObj(table, data5);
    // removeObj(table, data6);
    // removeObj(table, data1);

    //  printTable(table);
    // freeTable(table);

//    Table* table = createTable(4, STR_TYPE, 4);
//        char *p = "hello";
//       char * h = "h";
//       char * l ="l";
//       char * pp = "p";
//       char * g = "g";
//       char * ggg = "ggg";
//       char * ggH = "ggH";
//       char * m  = "m";
//       char * q = "q";
//       char * u = "u";
//     add(table, p);
//     add(table, p);
//     add(table, l);
//     add(table ,pp);
//     add(table, g);
//     add(table, ggg);
//     add(table, ggH);
//     add(table, m);
//     add(table, q);
//     add(table, u);
//     printTable(table);
//     int x = 1;
//     int* data = &x;
//     removeObj(table, data);
//     removeObj(table, NULL);
//     char *s = "heelo";
//     add(NULL,s);
//     add(table,NULL);
//     char *z = "hhh";
//     search(NULL, p);
//     search(table, NULL);
//     printf("%s\n", (char*)search(table, p)->data);
//     if(search(table, z) == NULL){
//         printf("sucsses\n");
//     }
//     removeObj(table, p);
//     printf("\n");
//     if(search(table, p) == NULL){
//         printf("sucsses\n");
//     }
//     printTable(table);
//     printf("\n");
//     char * y ="y";
//     char * f = "f";
//     add(table, y);
//     add(table, f);
//     add(table, p);
//     add(table, p);
//     printTable(table);
//     freeTable(table);
   
//     return 0;

  


 Table* table = createTable(5, INT_TYPE, 3);
    int toAdd = 1;
    add(table, &toAdd);
    toAdd = 2;
    add(table, &toAdd);
    toAdd = 1;
    add(table, &toAdd);
    add(table, &toAdd);
    printf("\n");
    toAdd = 6;
    add(table, &toAdd);
    toAdd = 7;
    add(table, &toAdd);
    add(table, &toAdd);
    add(table, &toAdd);
    add(table, &toAdd);
    add(table, &toAdd);
    add(table, &toAdd);
    add(table, &toAdd);
    add(table, &toAdd);
    add(table, &toAdd);
    add(table, &toAdd);
    printf("\n");
    printTable(table);
    printf("\n");
    toAdd = 1;
    removeObj(table, &toAdd);
    removeObj(table, &toAdd);
    removeObj(table, &toAdd);
    toAdd = 2;
    removeObj(table, &toAdd);
    toAdd = 6;
    removeObj(table, &toAdd);
    toAdd = 7;
    removeObj(table, &toAdd);
    printTable(table);
    freeTable(table);
    return 0;



}