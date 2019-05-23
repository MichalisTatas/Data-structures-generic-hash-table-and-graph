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
    // temp->adjacentNode = NULL;
    // temp->next = NULL;   

    if(HTSize(graph->hash) == 0)
        InitializeHash(graph->hash);
    
    graph->hash = HTInsert(graph->hash, vertex, temp);
}

void UGRemoveVertex(UGGraph* graph, char* vertex)
{
    HTRemove(graph->hash, vertex);   //how to remove it from any adjacent list
}

UGGraph* UGAddEdge(UGGraph* graph, char* vertex1, char* vertex2)
{
    HTNode* adjacentnode = malloc(sizeof(HTNode));
    HTItem temp = malloc(sizeof(HTItem));
    int index;

    //for the first vertex
    //get his adjacent list and add at the end a pointer to vertex 2

    index = HashFunction(vertex2, graph->hash->maxSize);

    adjacentnode = graph->hash->array[index];       //find the vertex in the list of the array position since its a hash table
    while(strcmp(adjacentnode->key, vertex2) != 0)
        adjacentnode = adjacentnode->next;
    
    HTGet(graph->hash, vertex1, &temp);
    
    if(temp != NULL)
    {
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = malloc(sizeof(HTItem));
        temp->next->adjacentNode = adjacentnode;
        // temp->next->next = NULL;
    }
    else
    {
        printf("DSFDFS");
        // temp = malloc(sizeof(HTItem));
        temp->adjacentNode = adjacentnode;
        // temp->next = NULL;
    }


    //for the first vertex
    //get his adjacent list and add at the end a pointer to vertex 2

    index = HashFunction(vertex1, graph->hash->maxSize);
    adjacentnode = graph->hash->array[index];       //find the vertex in the list of the array position since its a hash table
    while(strcmp(adjacentnode->key, vertex1) != 0)
        adjacentnode = adjacentnode->next;
    
    HTGet(graph->hash, vertex2, &temp);
    
    if(temp != NULL)
    {
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = malloc(sizeof(HTItem));
        temp->next->adjacentNode = adjacentnode;
        // temp->next->next = NULL;
    }
    else
    {
        // temp = malloc(sizeof(HTItem));
        temp->adjacentNode = adjacentnode;
        // temp->next = NULL;
    }
    return graph;
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















