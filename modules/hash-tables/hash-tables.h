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
    int maxSize;
    HTNode** array;
}HashTable;


void (*visit)(HashTable* hash, char* key, HTItem* pitem);
HashTable* HTCreate();
int HTSize(HashTable* hash);
bool HTGet(HashTable* hash, char* key, HTItem* pitem);
int HashFunction(char* key, int max);
HashTable* reHashing(HashTable* hash);
HashTable* HTInsert(HashTable* hash, char* key, HTItem item);
void HTRemove(HashTable* hash, char* key);
void HTVisit(HashTable* hash, void (*visit)(HashTable* hash, char* key, HTItem* pitem));
void RecursiveInsertAndDelete(HTNode* node, HashTable* hash);
void HTDestroy(HashTable* hash);
void destroy(HTNode* node);

void InitializeHash(HashTable* hash);