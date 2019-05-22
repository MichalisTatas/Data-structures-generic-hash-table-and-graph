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
    hash->maxSize = 10;

    hash = HTInsert(hash, "foo", 5);
    hash = HTInsert(hash, "boo", 4);
    hash = HTInsert(hash, "goo", 6);
    hash = HTInsert(hash, "koo", 7);
    hash = HTInsert(hash, "loo", 3);
    hash = HTInsert(hash, "poo", 9);
    
    HTVisit(hash,visit);

    printf("Size of hash is : %d\n", HTSize(hash));

    hash = HTInsert(hash, "goo", 11);
    hash = HTInsert(hash, "doo", 45);
    hash = HTInsert(hash, "aoo", 23);
    hash = HTInsert(hash, "uoo", 2);
    hash = HTInsert(hash, "roo", 13);
    hash = HTInsert(hash, "woo", 16);

    HTItem* pitem = malloc(sizeof(int*));
    HTGet(hash, "koo", pitem);
    printf("HTget value : %d \n",*pitem);
    HTRemove(hash, "koo");

    HTVisit(hash,visit);
    printf("Size of hash is : %d\n", HTSize(hash));
    printf("Sizedsfgdfgd gdsgfd : %d\n", hash->maxSize);
    Destroy(hash);
    free(pitem);
    return 0;
}