
#include "GenericHashTable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Table *createTable(int size, int dType, int listLength)
{
    if (size > 0 && (dType == 1 || dType == 0) && listLength > 0)
    { //if all the parameters is valid continue
        Table *table;
        table = (Table *)malloc(size * sizeof(Table)); //allocating a memory in the table
        table->dType = dType;
        table->size = size;
        table->listLength = listLength;
        table->arr = (struct Object **)malloc(sizeof(struct Object *) * size);
        for (int i = 0; i < size; i++)
        {
            table->arr[i] = (Object *)malloc(sizeof(Object) * listLength);
        }

        return table;
    }
    else //there is a problem in the parameters
    {
        printf("there is a problem in the parameters  ");
        return -1;
    }
}

int add(Table *table, void *data)
{
    if (table == NULL)
    { //check if the table is NULL
        printf("the table is NULL");
        return -1;
    }
    else
    { //if the table is not NULL
        if (data == NULL)
        { //check if hte table is NULL
            printf("the data is NULL");
            return -1;
        }

        else //the data is not NULL
        {

            if (table->dType == INT_TYPE) // data type is Integer
            {
                Object *ob;
                int intHash = 0;
                int *dataCopy = (int *)malloc(sizeof(int));
                strcpy(dataCopy, data);
                ob = createObject(dataCopy);
                intHash = intHashFun(data, table->size);
                table->arr[intHash]->next = ob;
            }
            else
            {
            }
        }
    }
}
Object *createObject(void *data)
{
    Object *ob = (Object *)malloc(sizeof(Object));
    strcpy(ob->data, data);
    return ob;
}
void freeObject(Object *obj, int type)
{
    free(obj->next);
    free(obj);
}
void printTable(Table *table)
{
}
void freeTable(Table *table)
{
    for (int i = 0; i < table->size; i++)
    {
        free(table->arr[i]);
    }
    free(table);
}
int intHashFun(int *key, int origSize)
{
    return (*key) % origSize;
}
int strHashFun(char *key, int origSize)
{

    int sum = 0;
    for (int i = 0; i < len(key); i++)
    {
        sum = sum + key[i];
    }
    return sum % origSize;
}
