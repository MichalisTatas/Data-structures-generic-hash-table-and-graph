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
int HTSize(HashTable*);
bool HTGet(HashTable*, char*, HTItem*);
int HashFunction(char*, int);
HashTable* reHashing(HashTable*);
void HTInsert(HashTable*, char*, HTItem);
void HTRemove(HashTable*, char*);
void HTVisit(HashTable*, void (*visit)(HashTable* hash, char* key, HTItem* pitem));

void InitializeHash(HashTable*);
void HTPrint(HashTable*);