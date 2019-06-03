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

void recursiveDeleteAdjacentList(UGGraph* graph, char* vertex, node* item) //destroys the adjacent list of a node recursively
{
    if(item == NULL)
        return;
    recursiveDeleteAdjacentList(graph, vertex, item->next);
    UGRemoveEdge(graph, vertex, item->adjacentNode->key);
}

void UGRemoveVertex(UGGraph* graph, char* vertex)
{
    HTNode* vertex1pointer = findVertex(graph, vertex);
    recursiveDeleteAdjacentList(graph, vertex, vertex1pointer->item);   
    HTRemove(graph->hash, vertex);
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
    
    node* pitem; // = malloc(sizeof(HTItem));
    pitem = vertex1pointer->item;

    if(pitem != NULL) {
        while(pitem->next != NULL)
            pitem = pitem->next;
        pitem->next = malloc(sizeof(HTItem));
        pitem->next->adjacentNode = vertex2pointer;
        pitem->next->next = NULL; 
    }   
    else {
        vertex1pointer->item = malloc(sizeof(HTItem*));
        pitem = vertex1pointer->item;
        pitem->adjacentNode = malloc(sizeof(HTNode));
        pitem->adjacentNode = vertex2pointer;
        pitem->next = NULL;
        // vertex1pointer->item = pitem;
        // vertex1pointer->item->adjacentNode = vertex2pointer;
        // vertex1pointer->item->next = NULL;
    } 

    // second insert vertex1 int the adjacent list of vertex2
    
    node* pitem1  = malloc(sizeof(HTItem));
    pitem1 = vertex2pointer->item;

    if(pitem1 != NULL) {
        while(pitem1->next != NULL)
            pitem1 = pitem1->next;
        pitem1->next = malloc(sizeof(HTItem));
        pitem1->next->adjacentNode = vertex1pointer;
        pitem1->next->next = NULL; 
    }   
    else {
        vertex2pointer->item = malloc(sizeof(HTItem*));
        pitem1 = vertex2pointer->item;
        pitem1->adjacentNode = malloc(sizeof(HTNode));
        pitem1->adjacentNode = vertex1pointer;
        pitem1->next = NULL;
        // vertex2pointer->item = pitem1;
        // vertex2pointer->item->adjacentNode = vertex1pointer;
        // vertex2pointer->item->next = NULL;
    }
    
    return graph;
}

void UGRemoveEdge(UGGraph* graph, char* vertex1, char* vertex2)
{
    HTNode* temp1 = findVertex(graph, vertex1);
    HTNode* temp2 = findVertex(graph, vertex2);
    node* fast = malloc(sizeof(node));
    node* slow = malloc(sizeof(node));

    slow = temp1->item;
    if(slow->next == NULL) {
        temp1->item = NULL;
        free(slow);
    }
    else if(!strcmp(slow->adjacentNode->key, vertex2)) {
        temp1->item = slow->next;
        free(slow);
    }
    else {
        fast = slow->next;
        while(strcmp(fast->adjacentNode->key, vertex2)) {
            slow = fast->next;
            fast = fast->next;
        }
        slow->next = fast->next;
        free(fast);
    }

    slow = temp2->item;
    if(slow->next == NULL) {
        temp2->item = NULL;
        free(slow);
    }
    else if(!strcmp(slow->adjacentNode->key, vertex1)) {
        temp2->item = slow->next;
        free(slow);
    }
    else {
        fast = slow->next;
        while(strcmp(fast->adjacentNode->key, vertex1)) {
            slow = fast->next;
            fast = fast->next;
        }
        slow->next = fast->next;
        free(fast);
    }
}

HTItem UGGetAdjacent(UGGraph* graph, char* vertex)
{
    HTItem temp = malloc(sizeof(HTItem));

    HTGet(graph->hash, vertex, &temp);

    return temp;
}

UGGraph* CreateDataGraph(UGGraph* graph)           //copies the given graph to a new one and returns it
{
    UGGraph* DataGraph = UGCreate(sizeof(int), false);
    
    HTNode* vertextpr;
    for(int i=0; i<graph->hash->maxSize; i++) {

        vertextpr = graph->hash->array[i];
        if(vertextpr != NULL) {
            UGAddVertex(DataGraph, vertextpr->key);

            if(vertextpr->next != NULL) {
                while(vertextpr != NULL) {
                    UGAddVertex(DataGraph, vertextpr->key);
                    vertextpr = vertextpr->next;
                }
            }
        }
    }    
    return DataGraph;
}

HTItem UGShortestPath(UGGraph* graph, char* vertex1, char* vertex2)
{
    //first i need yo create a graph with the same
    //keys but with the struct data as HTItem
    UGGraph* DataGraph = CreateDataGraph(graph);
    
    
    
    // return ?
}

void UGDestroy(UGGraph* graph)
{
    HTDestroy(graph->hash);
    free(graph);
}




















    