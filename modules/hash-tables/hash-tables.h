#include "HTmoduleTypes.h"
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
    int dataSize;
    bool isString;
    int size;
    int maxSize;
    HTNode** array;
}HashTable;


void (*visit)(HashTable* hash, char* key, HTItem pitem);

HashTable* HTCreate(int dataSize ,bool isString);
int HTSize(HashTable* hash);
bool HTGet(HashTable* hash, char* key, HTItem* pitem);
int HashFunction(char* key, int max);
HashTable* HTInsert(HashTable* hash, char* key, HTItem item);
void HTRemove(HashTable* hash, char* key);
void HTVisit(HashTable* hash, void (*visit)(HashTable* hash, char* key, HTItem pitem));
void HTDestroy(HashTable* hash);

void printht(HashTable* hash);
void printstring(HashTable* hash);
HTItem* AssignValue(HashTable* hash, HTItem initial, HTItem destination);
void InitializeHash(HashTable* hash);
HashTable* reHashing(HashTable* hash);
void RecursiveInsertAndDelete(HTNode* node, HashTable* hash);
void destroy(HTNode* node);