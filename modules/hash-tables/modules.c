#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules.h"

HashTable* HTCreate()
{
    HashTable* table = malloc(sizeof(HashTable));
    table->size = 0;
    return table;
}

int HTSize(HashTable* hash)
{
    return hash->size;
}

bool HTGet(HashTable* hash, char* key, HTItem* pitem)
{
    for(int i=0; i<hash->maxSize; i++)
    {
        if(hash->array[i] != NULL)
        {
            HTNode* temp = hash->array[i];
            while(temp != NULL)
            {
                if(strcmp(temp->key, key)==0)
                {
                    *pitem = temp->item;
                    return true;
                }
                temp = temp->next;    
            }
        }
    }
    return false;
}

int HashFunction(char* key, int max)
{
    return *key%max;
}

HashTable* reHashing(HashTable* hash)
{
    printf("Rehashing the hash due to number of nodes \n");
    HashTable* table1  = HTCreate();
    table1->maxSize = hash->maxSize*2;
    // InitializeHash(table1);
    HTNode* list;
    
    for(int i=0; i<hash->maxSize; i++)
    {
        list = hash->array[i];
        if(list != NULL)
        {
            while(list->next != NULL)
            {
                HTInsert(table1, list->key, list->item);
                list = list->next;
            }
        }
    }

    // hash = table1;
    return table1;
}

void InitializeHash(HashTable* hash)
{
    hash->array = malloc(hash->maxSize*sizeof(HTNode*));
    for(int i=0; i<hash->maxSize; i++)
    {
        hash->array[i] = malloc(sizeof(HTNode));
        hash->array[i] = NULL;
    }
}

void HTInsert(HashTable* hash, char* key, HTItem item)
{
    if(hash->size == 0)
    {
        hash->maxSize = 10;
        InitializeHash(hash);
    }
    HTNode* temp;
    HTNode* node = malloc(sizeof(HTNode));
    node->key = key;
    node->item = item;
    node->next = NULL;
    int index = HashFunction(key, hash->maxSize);
    if(hash->array[index] == NULL)
    {
        hash->array[index] = node;
        hash->size++;
    }
    else
    {
        temp = hash->array[index];
        while(temp->next != NULL)
        {
            if(temp->key == key)
            {
                temp->item = node->item;
                node->key = NULL;
                hash->size++;
            }
            temp = temp->next;
        }
        if(node->key != NULL)
        {
            temp->next = node;
            hash->size++;
        }
    }
     if(hash->size/hash->maxSize > 0.9)
        hash = reHashing(hash);
}

void HTRemove(HashTable* hash, char* key)
{
    int index = HashFunction(key, hash->maxSize);
    HTNode* slow;
    HTNode* fast;
    fast = hash->array[index];
    while(fast->key != key)
    {
        slow = fast;
        fast = fast->next;
    }
    if(fast == hash->array[index])
    {
        if(fast->next == NULL)
            hash->array[index] = NULL;
        else
            hash->array[index] = fast->next;
    }
    else
        slow->next = fast->next;
    hash->size--;
    free(fast);
}

void HTVisit(HashTable* hash, void (*visit)(HashTable* hash, char* key, HTItem* pitem))
{
    HTNode* temp;
    for(int i=0; i<hash->maxSize; i++)
    {
        if(hash->array[i] != NULL)
        {
            temp = hash->array[i];
            while(temp != NULL)
            {
                visit(hash, temp->key, &temp->item);
                temp = temp->next;    
            }
        }
    }
}