#include <stdlib.h>
#include <string.h>
#include "graph.h"

UGGraph* UGCreate(int dataSize ,bool isString)
{
    UGGraph* graph = malloc(sizeof(UGGraph));
    
    graph->hash = HTCreate(dataSize ,isString);
    graph->Size = 0;
    
    return graph;
}

void UGAddVertex(UGGraph* graph, char* vertex)
{
    HTItem temp = NULL;    
    graph->hash = HTInsert(graph->hash, vertex, temp);
}

void UGRemoveVertex(UGGraph* graph, char* vertex)
{
    HTRemove(graph->hash, vertex);   //how to remove it from any adjacent list
}

HTNode* findVertex(UGGraph* graph, char* vertex)       //returns pointer to vertex in the hash table
{
    HTNode* vertexPosition = malloc(sizeof(HTNode));
    int index = HashFunction(vertex, graph->hash->maxSize);
    vertexPosition = graph->hash->array[index];

    if(graph->hash->array[index] == NULL) {
        printf("wrong string\n");
        return NULL;
    }
    if(vertexPosition->next == NULL)
        return vertexPosition;
    while(strcmp(vertexPosition->key, vertex) != 0)
        vertexPosition = vertexPosition->next;                           //finds vertex1 in the hash table
    return vertexPosition;
}

UGGraph* UGAddEdge(UGGraph* graph, char* vertex1, char* vertex2)
{
    HTNode* vertex1pointer = malloc(sizeof(HTNode)); 
    vertex1pointer = findVertex(graph, vertex1);    //pointer to vertex1 in the hash table
    
    HTNode* vertex2pointer = malloc(sizeof(HTNode)); 
    vertex2pointer = findVertex(graph, vertex2);    //pointer to vertex2 in the hash table
    
    // first insert vertex2 in the adjacent list of vertex1
    
    HTItem* pitem = malloc(sizeof(HTItem));
    *pitem = vertex1pointer->item;
    // HTGet(graph->hash, vertex1, pitem);

    if((*pitem) != NULL) {
        while((*pitem)->next != NULL)
            (*pitem) = (*pitem)->next;
        (*pitem)->next = malloc(sizeof(HTItem));
        (*pitem)->next->adjacentNode = vertex2pointer;
        (*pitem)->next->next = NULL; 
    }   
    else {
        vertex1pointer->item = malloc(sizeof(HTItem*));
        vertex1pointer->item->adjacentNode = vertex2pointer;
        vertex1pointer->item->next = NULL;
    } 

    // second insert vertex1 int the adjacent list of vertex2
    
    HTItem* pitem1  = malloc(sizeof(HTItem));
    *pitem1 = vertex2pointer->item;
    // HTGet(graph->hash, vertex2, pitem1);

    if((*pitem1) != NULL) {
        while((*pitem1)->next != NULL)
            (*pitem1) = (*pitem1)->next;
        (*pitem1)->next = malloc(sizeof(HTItem));
        (*pitem1)->next->adjacentNode = vertex1pointer;
        (*pitem1)->next->next = NULL; 
    }   
    else {
        vertex2pointer->item = malloc(sizeof(HTItem*));
        vertex2pointer->item->adjacentNode = vertex1pointer;
        vertex2pointer->item->next = NULL;
    }
    
    return graph;
}

void UGRemoveEdge(UGGraph* graph, char* vertex1, char* vertex2)
{
    HTNode* temp = findVertex(graph, vertex1);
    HTItem* fast;
    HTItem* slow;

    fast = &temp->item;
    while(strcmp((*fast)->adjacentNode->key, vertex2)) {
        slow = fast;
        *fast = (*fast)->next;
    }
    if(memcmp(fast, &temp->item, sizeof(HTItem)) == 0) {
        if((*fast)->next == NULL)
            temp->item = NULL;
        else
            temp->item = (*fast)->next;
    }
    else
        (*slow)->next = (*fast)->next;


    HTNode* temp1 = findVertex(graph, vertex2);
    fast = &temp1->item;
    while(strcmp((*fast)->adjacentNode->key, vertex1)) {
        slow = fast;
        *fast = (*fast)->next;
    }
    if(memcmp(fast, &temp->item, sizeof(HTItem)) == 0) {
        if((*fast)->next == NULL)
            temp1->item = NULL;
        else
            temp1->item = (*fast)->next;
    }
    else
        (*slow)->next = (*fast)->next;
}

HTItem UGGetAdjacent(UGGraph* graph, char* vertex)
{
    HTItem temp = malloc(sizeof(HTItem));

    HTGet(graph->hash, vertex, &temp);

    return temp;
}

void UGDestroy(UGGraph* graph)
{
    HTDestroy(graph->hash);
    free(graph);
}




















