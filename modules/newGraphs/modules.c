#include <stdlib.h>

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
     HTGet();
}