
#include "GenericHashTable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Table *createTable(int size, int dType, int listLength)
{
    if (size > 0 && (dType == 1 || dType == 0) && listLength > 0)
    { //if all the parameters is valid continue
        Table *table;
        table = (Table *)malloc(size * sizeof(Table)); //allocating a memory for the table
        table->dType = dType;
        table->size = size;
        table->listLength = listLength;
        table->arr = (struct Object **)malloc(sizeof(struct Object *) * size); //allocate the memory for the array "the column"
        for (int i = 0; i < size; i++)
        { //allocate memory for the objects "the rows"
            for (int j = 0; j < listLength; j++)
            {
                table->arr[i][j] = createObject(NULL);
            }

            return table;
        }
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
    Object *ob = (Object *)malloc(sizeof(Object)); // allocation memory for the new object
    strcpy(ob->data, data);
    return ob;
}
void freeObject(Object *obj, int type)
{
    //?????????????????/   free(obj->next);
    ////type ?????????????????//
    free(obj);
}
void printTable(Table *table)
{
    Object *ob;
    if (table == NULL)
    {
        printf("the table is NULL");
        return;
    }
    else
    {
        for (int i = 0; i < table->size; i++)
        {
            printf("[%d]    ", i);
            for (int j = 0; j < table->listLength; j++)
            {
                if (table->arr[i] == NULL)
                {
                    break; //go to the next column
                }
                else //we have data in that index
                {
                    printf("%d  -->    ", table->arr[i]->data);
                }
            }
            printf("\n");
        }
    }
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
