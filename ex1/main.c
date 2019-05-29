#include <stdio.h>
#include <stdlib.h>
#include "hash-tables.h"

// void myvisit(HashTable* hash, char* key, HTItem* pitem)
// {
//     printf("%s\n", key);
// }

void myvisit(HashTable* hash, char* key, HTItem pitem) {
    printf("%p \n", pitem);
}

void integers() {
    visit = myvisit;
    printf("peaki ali8eias\n");
    HashTable* hash = HTCreate(sizeof(int*) ,false);
    hash->maxSize = 5;
    HTItem intptr1 = malloc(sizeof(int));
    intptr1 = (int*)5;
    hash = HTInsert(hash, "foo", intptr1);

    HTItem intptr2 = malloc(sizeof(int));
    intptr2 = (int*)6;
    hash = HTInsert(hash, "doo", intptr2);

    HTItem intptr3 = malloc(sizeof(int));
    intptr3 = (int*)1;
    hash = HTInsert(hash, "goo", intptr3);

    HTItem intptr4 = malloc(sizeof(int));
    intptr4 = (int*)7;
    hash = HTInsert(hash, "loo", intptr4);

    HTItem* pitem = malloc(sizeof(int));
    HTGet(hash, "foo", pitem);
    printf("%d \n", *(int*)pitem);

    printf("Size of hash is : %d\n", HTSize(hash));

    HTVisit(hash,visit);

    HTRemove(hash, "goo");

    printf("Size of hash is : %d\n", HTSize(hash));

    HTVisit(hash,visit);

    HTDestroy(hash);
}

void string_visit(HashTable* hash, char* key, HTItem pitem) {
    printf("%s \n", (char*)pitem);
}

void strings() {
    visit = string_visit;
    HashTable* hash = HTCreate(sizeof(char*) ,true);
    hash->maxSize = 5;

    HTItem intptr1 = malloc(sizeof(char*));
    intptr1 = (char*)"geia";
    hash = HTInsert(hash, "foo", intptr1);
    
    HTItem intptr2 = malloc(sizeof(char*));
    intptr2 = (char*)"mixalh";
    hash = HTInsert(hash, "boo", intptr2);

    HTItem intptr3 = malloc(sizeof(char*));
    intptr3 = (char*)"tata";
    hash = HTInsert(hash, "goo", intptr3);

    HTItem intptr4 = malloc(sizeof(char*));
    intptr4 = (char*)"zwo";
    hash = HTInsert(hash, "loo", intptr4);

    HTItem intptr5 = malloc(sizeof(char*));
    intptr5 = (char*)"kwlo";
    hash = HTInsert(hash, "hoo", intptr5);
    
    HTItem intptr6 = malloc(sizeof(char*));
    intptr6 = (char*)"mono";
    hash = HTInsert(hash, "joo", intptr6);

    HTItem intptr7 = malloc(sizeof(char*));
    intptr7 = (char*)"di";
    hash = HTInsert(hash, "moo", intptr7);

    HTItem intptr8 = malloc(sizeof(char*));
    intptr8 = (char*)"xaax";
    hash = HTInsert(hash, "soo", intptr8);


    printf("Size of hash is : %d\n", HTSize(hash));

    HTVisit(hash,visit);

    HTRemove(hash, "goo");

    HTVisit(hash,visit);

    HTDestroy(hash);
}

int main(void) {
    integers();
    strings();    
    return 0;
}