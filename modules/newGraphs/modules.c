#include <stdlib.h>
#include <string.h>
#include "graph.h"

UGGraph* UGCreate()
{
    UGGraph* graph = malloc(sizeof(UGGraph));
    
    graph->hash = HTCreate();
    graph->Size = 0;
    
    return graph;
}

void UGAddVertex(UGGraph* graph, char* vertex)
{
    HTItem temp = malloc(sizeof(HTItem));
    
    temp->adjacentNode  = NULL;
    temp->next = NULL;
    
    if(HTSize(graph->hash) == 0)
        InitializeHash(graph->hash);
    
    graph->hash = HTInsert(graph->hash, vertex, temp);
}

void UGRemoveVertex(UGGraph* graph, char* vertex)
{
    HTRemove(graph->hash, vertex);   //how to remove it from any adjacent list
}

void UGAddEdge(UGGraph* graph, char* vertex1, char* vertex2)
{
    HTItem temp;
    HTItem adjacentlist;
    int index;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    HTNode* adjacentnode;





    

    //for the first vertex
    //get his adjacent list and add at the end a pointer to vertex 2

    index = HashFunction(vertex2, graph->hash->maxSize);
    HTGet(graph->hash, vertex1, &adjacentlist);
    temp = adjacentlist;                        //dont kow if necessary
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = malloc(sizeof(HTItem));
    temp->next->next = NULL;

    adjacentnode = graph->hash->array[index];       //find the vertex in the list of the array position since its a hash table
    while(strcmp(adjacentnode->key, vertex2) != 0)
        adjacentnode = adjacentnode->next;

    temp->next->adjacentNode = adjacentnode;

    //for the first vertex
    //get his adjacent list and add at the end a pointer to vertex 2

    index = HashFunction(vertex1, graph->hash->maxSize);
    HTGet(graph->hash, vertex2, &adjacentlist);
    temp = adjacentlist;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = malloc(sizeof(HTItem));
    temp->next->next = NULL;

    adjacentnode = graph->hash->array[index];       //find the vertex in the list of the array position since its a hash table
    while(strcmp(adjacentnode->key, vertex1) != 0)
        adjacentnode = adjacentnode->next;

    temp->next->adjacentNode = adjacentnode;
}

// void UGRemoveEdge(UGGraph* graph, char* vertex1, char* vertex2)
// {
//     HTItem temp;

//     HTGet(graph->hash, vertex1, temp);
//     if(strcmp(temp->adjacentNode->item, vertex2) == 0)
//         if(temp->next == NULL)
//             temp = NULL;
//         else 
// }

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















