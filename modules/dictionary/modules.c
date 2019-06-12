#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dictionary.h"

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

void FindPath(char* source, char* destination)
{
    char* a = malloc(strlen(source)*sizeof(char));
    char* b = malloc(strlen(source)*sizeof(char));
    UGGraph* graph = UGCreate(sizeof(char*), true);
    char* curr = NULL;
    size_t sz;
    FILE *fp;
    HTNode* word1vertex;
    HTNode* word2vertex;
    
    fp = fopen("words.txt", "r");
    while((getline(&curr, &sz, fp)) != -1)
    {
        if((strlen(curr) -1 ) == strlen(source)){
            UGAddVertex(graph, curr);
        }
    }

    fclose(fp);


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
    UGShortestPath(graph, source, destination);
}