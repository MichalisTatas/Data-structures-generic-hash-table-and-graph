#include <stdio.h>
#include "hash-tables.h"
#pragma once

typedef struct UGGraph
{
    int Size;
    HashTable* hash;
}UGGraph;

UGGraph* UGCreate();
void UGAddVertex(UGGraph* graph, char* vertex);
void UGRemoveVertex(UGGraph* graph, char* vertex);
void UGAddEdge(UGGraph* graph, char* vertex1, char* vertex2);
// UGRemoveEdge(UGGraph* graph, char* vertex1, char* vertex2);
// UGGetAdjacent(UGGraph* graph, char* vertex);
// UGShortestPath(UGGraph* graph, char* vertex1, char* vertex2);
// UGDestroy(UGGraph* graph);