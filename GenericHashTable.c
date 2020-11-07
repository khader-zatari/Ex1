
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
        table->tabelNewSize = size;

        table->arr = (struct Object **)malloc(sizeof(struct Object *) * size); //allocate the memory for the array "the column"

        return table;
    }
    else //there is a problem in the parameters
    {
        printf("there is a problem in the parameters  ");
        return NULL;
    }
}
Object *createObject(void *data)
{
    Object *ob = (struct Object *)malloc(sizeof(struct Object)); //allocat memory for the object
    ob->data = data;
    return ob;
}
void printTable(Table *table)
{

    if (table == NULL) //if the table is not initated print error
    {
        printf("the table is NULL");
        return;
    }
    else //the table is initated
    {

        Object *head;

        for (int i = 0; i < table->tabelNewSize; i++)
        {

            head = table->arr[i];
            printf("[%d]\t", i);
            //printf("%d\t-->\t", *(int *)head->data);

            for (int j = 0; j < table->listLength; j++)
            {
                if (head == NULL)
                {
                    continue; //go to the next column
                }
                else //we have data in that index
                {
                    if (table->dType == INT_TYPE)
                    {
                        printf("%d\t-->\t", *(int *)head->data);
                    }
                    if (table->dType == STR_TYPE)
                    {
                        printf("%s\t-->\t", (char *)head->data);
                    }

                    if (head->next != NULL)
                    {
                        head = head->next;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            printf("\n");
        }
    }
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
Object *search(Table *table, void *data)
{

    Object *head;
    Object *find;
    int success = 0;
    for (int i = 0; i < table->tabelNewSize; i++)
    {
        head = table->arr[i];
        if (table->dType == INT_TYPE)
        {
            success = isEqual(INT_TYPE, head->data, data);
        }
        if (table->dType == STR_TYPE)
        {
            success = isEqual(STR_TYPE, head->data, data);
        }

        if (success == 0)
        {
            find = head;
            return find;
        }
        if (success != 0)
        {
            printf("not working ");
            return NULL;
        }

        for (int j = 0; j < table->listLength - 1; j++)
        {

            if (table->dType == INT_TYPE)
            {
                success = isEqual(INT_TYPE, head->data, data);
            }
            if (table->dType == STR_TYPE)
            {
                success = isEqual(STR_TYPE, head->data, data);
                printf("hello");
            }
            if (success == 0)
            {
                find = head;
                return find;
            }
            if (success != 0)
            {
                printf("not working ");
                return NULL;
            }
            head = head->next;
        }
    }
}
int add(Table *table, void *data)
{

    if (table == NULL) //check if the table is NULL
    {
        printf("the table is NULL");
        return -1;
    }
    else //if the table is not NULL
    {
        if (data == NULL) //check if hte table is NULL
        {
            printf("the data is NULL");
            return -1;
        }
        else //the data is not NULL
        {
            int intHash = 0;
            Object *ob;
            if (table->dType == INT_TYPE) // data type is Integer
            {
                intHash = intHashFun((int *)data, table->size);
                int *intVar = (int *)malloc(sizeof(int));
                *intVar = *(int *)data;
                ob = createObject(intVar);
                ob->next = NULL;
            }
            else
            {
                intHash = strHashFun((char *)data, table->size);
                char *intVar = (char *)malloc(sizeof(char));
                intVar = (char *)data;
                ob = createObject(intVar);
                ob->next = NULL;
            }

            if (table->arr[intHash * table->d] == NULL)
            {
                table->arr[intHash * table->d] = ob;
                return intHash * table->d;
            }
            int end = 0;
            end = (table->listLength) * (table->d);

            for (int x = 0; x < table->d; x++)
            {

                Object *head = table->arr[(intHash * table->d) + x];
                if (head == NULL)
                {
                    table->arr[(intHash * table->d) + x] = ob;
                    return (intHash * table->d) + x;
                }
                while (head->next != NULL)
                {
                    end -= 1;          //if end == 1 i should duble the array
                    head = head->next; // now iam at the end of the array
                }
                if (end != 1 && (end - 1) % table->listLength == 0)
                {
                    end -= 1;

                    continue;
                }
                if (end != 1)
                {
                    head->next = ob;
                    return (intHash * table->d) + x;
                }
                else // double the array and enter the object
                {
                    table->arr = (Object **)realloc(table->arr, sizeof(Object *) * table->size * table->d * 2);
                    table->d = table->d * 2;
                    table->tabelNewSize = table->size * table->d;                       //this should be under the d
                    for (int a = table->tabelNewSize / 2; a < table->tabelNewSize; a++) // put null in the last half of the array
                    {
                        table->arr[a] = NULL;
                    }
                    for (int z = (table->size * table->d / 2) - 1; z > 0; z--)
                    {
                        table->arr[(z * 2)] = table->arr[z];
                        table->arr[z] = NULL;
                        //                 }
                    }
                    /*add the object to it's new index in the head*/
                    for (int z = 0; z < table->d; z++)
                    {
                        if (table->arr[(intHash * table->d) + z] == NULL)
                        {
                            table->arr[(intHash * table->d) + z] = ob;
                            return (intHash * table->d) + z;
                        }
                    }
                }
            }
        }
    }
}
int removeObj(Table *table, void *data)
{
    // Store head node
    Object *head;
    Object *prev;
    int intHash;
    int red = table->listLength;
    if (table->dType == INT_TYPE) // data type is Integer
    {
        intHash = intHashFun((int *)data, table->size);
    }
    else
    {
        intHash = strHashFun((char *)data, table->size);
    }
    for (int i = 0; i < table->d; i++)
    {
        Object *temp = table->arr[(intHash * table->d) + i];
        Object *head;
        Object *prev;

        // If head node itself holds the key to be deleted
        if (temp != NULL && isEqual(table->dType, temp->data, data) == 0)
        {
            table->arr[(intHash * table->d) + i] = temp->next; // Changed head
            free(temp);                                        // free old head
            return (intHash * table->d) + i;
        }

        // Search for the key to be deleted, keep track of the
        // previous node as we need to change 'prev->next'
        while (temp != NULL && isEqual(table->dType, temp->data, data) != 0)
        {
            red -= 1;
            prev = temp;
            temp = temp->next;
        }

        // If key was not present in linked list
        if (temp == NULL && i == table->d - 1)
            return -1;
        if (temp == NULL && red == 0)
            continue;
        if (temp != NULL)
        {
            // Unlink the node from linked list
            prev->next = temp->next;

            free(temp); // Free memory
            return (intHash * table->d) + i;
        }
    }
}
void freeObject(Object *obj, int type)
{
    free(obj->data);
    free(obj);
}
void freeTable(Table *table)
{
    Object *prev;
    int tableCells = table->listLength * table->size;
    for (int i = 0; i < table->tabelNewSize; i++)
    {
        Object *temp = table->arr[i];
        while (temp != NULL)
        {

            prev = temp;
            temp = temp->next;
            freeObject(prev, table->dType);
        }
    }
    free(table->arr);
    free(table);
}