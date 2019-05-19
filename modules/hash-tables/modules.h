#include "modulesTypes.h"
#include <stdbool.h>
#pragma once

typedef struct HTNode
{
    char* key;
    HTItem item;
    struct HTNode* next;
}HTNode;

typedef struct HashTable
{
    int size;
    HTNode** array;
}HashTable;


void (*visit)(HashTable* hash, char* key, HTItem* pitem);
HashTable* HTCreate();
int HTSize(HashTable* hash);
bool HTGet(HashTable* hash, char* key, HTItem* pitem);
int HashFunction(char* key);
HashTable* reHashing(HashTable* hash);
void HTInsert(HashTable* hash, char* key, HTItem item);
void HTRemove(HashTable* hash, char* key);
void HTVisit(HashTable* hash, void (*visit)(HashTable* hash, char* key, HTItem* pitem));