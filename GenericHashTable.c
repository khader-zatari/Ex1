
#include "GenericHashTable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Table *createTable(int size, int dType, int listLength)
{
    if (size > 0 && (dType == 1 || dType == 0) && listLength > 0) //if all the parameters is valid continue
    {
        Table *table = (Table *)malloc(sizeof(Table)); //allocating a memory for the table
        table->dType = dType;
        table->size = size;
        table->listLength = listLength;
        table->d = 1;

        table->arr = (struct Object **)malloc(sizeof(struct Object *) * size); //allocate the memory for the array "the column"
        Object *head;
        for (int i = 0; i < size; i++)
        {
            table->arr[i] = (struct Object *)malloc(sizeof(struct Object));
            head = table->arr[i];
            head->data = NULL;
            for (int j = 0; j < listLength - 1; j++)

            {
                head = (struct Object *)malloc(sizeof(struct Object));
                head->data = NULL;
                head = head->next;
            }
        }
        // for (int i = 0; i < size; i++)
        // {
        //     for (int j = 0; j < listLength; j++)
        //     {
        //         Object *newObj =(Object *) malloc(sizeof(Object));
        //         if (newObj == NULL)
        //         {
        //             printf("not allocated");
        //             exit(0);
        //         }
        //         else
        //         {
        //             *table->arr = newObj;
        //             newObj->next = *table->arr;
        //             newObj->data = NULL;
        //         }
        //     }
        // }

        return table;
    }
    else //there is a problem in the parameters
    {
        printf("there is a problem in the parameters  ");
        return NULL;
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
                intHash = intHashFun((int *)data, table->size);
                printf("%d",intHash);
                Object *head = table->arr[intHash];

                for (int i = 0; i < table->listLength * table->d; i++)
                {
                    if (head->data == NULL)
                    {
                        // printf("%d\t",  data);
                        // printf("%d", *((int *)data));
                        head->data = &data;
                        printf("hello");
                        break;
                    }
                    if (head->next != NULL)
                        head = head->next;
                }
            }
            else
            {
            }
        }
    }
}

// Object *createObject(void *data)
// {
//     Object *ob = (Object *)malloc(sizeof(Object)); // allocation memory for the new object
//     strcpy(ob->data, data);
//     return ob;
// }

/*void freeObject(Object *obj, int type)
{
    //?????????????????/   free(obj->next);
    ////type ?????????????????//
    free(obj);
}*/
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
        Object *head;
        for (int i = 0; i < table->size; i++)
        {
            head = table->arr[i];
            printf("[%d]\t", i);
            for (int j = 0; j < table->listLength; j++)
            {
                if (head == NULL)
                {
                    break; //go to the next column
                }
                else //we have data in that index
                {
                    printf("%d\t-->\t", (head->data));
                    if (head->next != NULL)
                        head = head->next;
                }
            }
            printf("\n");
        }
    }
}
/*
void freeTable(Table *table)
{
    for (int i = 0; i < table->size; i++)
    {
        free(table->arr[i]);
    }
    free(table);
}*/
void freeTable(Table *table)
{
}
int intHashFun(int *key, int origSize)
{
    return (*key) % origSize;
}
int strHashFun(char *key, int origSize)
{
    int stln = strlen(key);
    int sum = 0;
    for (int i = 0; i < stln; i++)
    {
        sum = sum + key[i];
    }
    return sum % origSize;
}
int isEqual(int type, void *data1, void *data2)
{
    if (type == INT_TYPE || type == STR_TYPE)
    {
        if (type == INT_TYPE)
        {
            if (*(int *)data1 == *(int *)data2)
            {
                printf("its equal");
                return (0);
            }
            else
            {
                printf("it's not equal");
                return (-1);
            }
        }
        else
        {
            int data1Len = strlen((char *)data1);
            int data2Len = strlen((char *)data2);
            if (data2Len != data1Len)
            {
                printf("its not equale");
                return (-1);
            }
            else
            {

                for (int i = 0; i < data2Len; i++)
                {

                    if (*((char *)data1 + i) == *((char *)data2 + i))
                    {
                        if (i == data2Len - 1)
                        {
                            printf("its equal");
                            return (0);
                        }
                    }
                    else
                    {
                        printf("it's not equal");
                        return (-1);
                    }
                }
            }
        }
    }
    else
    {
        printf("the type is note defined ");
    }
}
Object* search(Table* table, void* data){
    if (table->dType == INT_TYPE)
    {
        Object *head;
        Object *find;
        for (int i = 0; i < table->size; i++)
        {
            head = table->arr[i];
            int success = isEqual(INT_TYPE, head->data, data);
            if (success == 0)
            {
                find = head;
                return find;
            }
            for (int j = 0; j < table->listLength - 1; j++)
            {

                int sucess = isEqual(INT_TYPE, head->data, data);
                if (success == 0)
                {
                    find = head;
                    return find;
                }
                head = head->next;
            }
        }
    }
    else
    {
        Object *head;
        Object *find;
        for (int i = 0; i < table->size; i++)
        {
            head = table->arr[i];
            int success = isEqual(STR_TYPE, head->data, data);
            if (success == 0)
            {
                find = head;
                return find;
            }
            for (int j = 0; j < table->listLength - 1; j++)
            {

                int sucess = isEqual(STR_TYPE, head->data, data);
                if (success == 0)
                {
                    find = head;
                    return find;
                }
                head = head->next;
            }
        }
    }
        
}
