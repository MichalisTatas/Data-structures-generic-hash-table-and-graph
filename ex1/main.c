#include <stdio.h>
#include <stdlib.h>
#include "modules.h"

void myvisit(HashTable* hash, char* key, HTItem* pitem)
{
    printf("%s\n", key);
}

int main(void)
{
    visit = myvisit;
    HashTable* hash = HTCreate();
    HTInsert(hash, "foo", 5);
    HTInsert(hash, "boo", 4);
    HTInsert(hash, "goo", 6);
    HTInsert(hash, "koo", 7);
    HTInsert(hash, "loo", 3);
    HTInsert(hash, "poo", 9);
    
    HTVisit(hash,visit);

    printf("Size of hash is : %d\n", HTSize(hash));

    HTInsert(hash, "goo", 11);
    HTInsert(hash, "doo", 45);
    HTInsert(hash, "aoo", 23);
    HTInsert(hash, "uoo", 2);
    HTInsert(hash, "roo", 13);
    HTInsert(hash, "woo", 16);
    HTItem* pitem = malloc(sizeof(int*));
    HTGet(hash, "koo", pitem);
    printf("HTget value : %d \n",*pitem);
    HTRemove(hash, "koo");

    HTVisit(hash,visit);
    printf("Size of hash is : %d\n", HTSize(hash));
    // printf("Sizedsfgdfgd gdsgfd : %d\n", hash->maxSize);
    return 0;
}