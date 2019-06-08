#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dictionary.h"

void printgraph(HashTable* hash) {
    HTNode* temp;
    for(int i=0; i<hash->maxSize; i++) {
         temp = hash->array[i];
         if(temp != NULL)
         {
                if(strncmp(temp->key, "cat", 3) == 0)
                    printf("PASPDASPDPAS");
            // printf("\n");
            // printf("%s -->", (char*)temp->key);
                if(temp->next != NULL) {
                    while(temp != NULL) {
                //         printf(" %s -->", temp->key);
                if(strncmp(temp->key, "cat", 3) == 0)
                    printf("PASPDASPDPAS");
                        temp = temp->next;
                    }
                }
         }
    }
}

bool isSimilar(char* word1, char* word2)
{
    char previouschar;
    for(int i=0; i<strlen(word1); i++) {
        previouschar = word1[i];
        for(char j='a'; j<='z'; j++) {
            word1[i] = j;
            if(strcmp(word1, word2) == 0)
                return true;
        }
        word1[i] = previouschar;
    }
        return false;
}

// void FindPath(char* source, char* destination)
// {
//     UGGraph* graph = UGCreate(sizeof(char*), true);
//     char* curr = NULL;
//     size_t sz;
//     FILE *fp;
//     fp = fopen("words.txt", "r");
//     while((getline(&curr, &sz, fp)) != -1)
//     {
//         if((strlen(curr) -1 ) == strlen(source)){
//             // printf("%s", curr);
//             UGAddVertex(graph, curr);
//         }
//     }
//     // printgraph(graph->hash);  
//     fclose(fp);

//     HTNode* word1vertex = malloc(sizeof(HTNode));
//     HTNode* word2vertex = malloc(sizeof(HTNode));

//     for(int i=0; i<graph->hash->maxSize; i++) {
//         for(int j=i+1; j <graph->hash->maxSize; j++) {
//             word1vertex = graph->hash->array[i];

//             while(word1vertex != NULL) {
//                 word2vertex = graph->hash->array[j];
//                 while(word2vertex != NULL) {
//                     if(isSimilar(word1vertex->key, word2vertex->key) == true)
//                        UGAddEdge(graph, word1vertex->key, word2vertex->key);
//                     word2vertex = word2vertex->next;
//                 }
//                 word1vertex = word1vertex->next;
//             }
//         }
//     }
//     printgraph(graph->hash);
//     UGShortestPath(graph, source, destination);
// }











void FindPath(char* source, char* destination)
{
    char* a = malloc(strlen(source)*sizeof(char));
    char* b = malloc(strlen(source)*sizeof(char));
    UGGraph* graph = UGCreate(sizeof(char*), true);
    char* curr = NULL;
    size_t sz;
    FILE *fp;
    fp = fopen("words.txt", "r");
    while((getline(&curr, &sz, fp)) != -1)
    {
        if((strlen(curr) -1 ) == strlen(source)){
            UGAddVertex(graph, curr);
        }
    }

    fclose(fp);

    HTNode* word1vertex;
    HTNode* word2vertex;

    for(int i=0; i<graph->hash->maxSize; i++) {
        word1vertex = graph->hash->array[i];
        while(word1vertex != NULL) {
            for(int j=i; j<graph->hash->maxSize; j++) {
                    word2vertex = graph->hash->array[j];
                    while(word2vertex != NULL) {
                        strcpy(a, word1vertex->key);
                        strcpy(b, word2vertex->key);
                        if(isSimilar(a, b) == true)
                            UGAddEdge(graph, word1vertex->key, word2vertex->key);
                        word2vertex = word2vertex->next;
                    }
            }
            word1vertex = word1vertex->next;
        }
    }
    // printgraph(graph->hash);
    UGShortestPath(graph, source, destination);
}