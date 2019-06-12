#include <stdio.h>
#include <stdlib.h>
#include "hash-tables.h"

void myvisit(HashTable* hash, char* key, HTItem pitem) {
    printf("%p \n", pitem);
}

void integers() {
    visit = myvisit;
    
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
    printf("pitem = %d  \n", *(int*)pitem);

    printf("Size of hash is : %d\n", HTSize(hash));

    // HTVisit(hash,visit);

    printht(hash);

    HTRemove(hash, "goo");

    printf("Size of hash is : %d\n", HTSize(hash));

    // HTVisit(hash,visit);
    
    printht(hash);

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
    intptr1 = (char*)"foo";
    hash = HTInsert(hash, "foo", intptr1);
    
    HTItem intptr2 = malloc(sizeof(char*));
    intptr2 = (char*)"goo";
    hash = HTInsert(hash, "goo", intptr2);

    HTItem intptr4 = malloc(sizeof(char*));
    intptr4 = (char*)"loo";
    hash = HTInsert(hash, "loo", intptr4);

    HTItem intptr5 = malloc(sizeof(char*));
    intptr5 = (char*)"hoo";
    hash = HTInsert(hash, "hoo", intptr5);
    
    HTItem intptr6 = malloc(sizeof(char*));
    intptr6 = (char*)"joo";
    hash = HTInsert(hash, "joo", intptr6);

    HTItem intptr7 = malloc(sizeof(char*));
    intptr7 = (char*)"moo";
    hash = HTInsert(hash, "moo", intptr7);

    HTItem intptr8 = malloc(sizeof(char*));
    intptr8 = (char*)"soo";
    hash = HTInsert(hash, "soo", intptr8);


    printf("Size of hash is : %d \n", HTSize(hash));

    // HTVisit(hash,visit);
    printstring(hash);

    printf("Removing node with key goo \n");
    HTRemove(hash, "goo");

    // HTVisit(hash,visit);
    printstring(hash);

    HTDestroy(hash);
}

int main(void) {
    printf("\nThis is for the integers \n");
    integers();
    printf("\nThis is for the strings \n");
    strings();    
    return 0;
}