#include <stdio.h>
#include <stdbool.h>
#include "hash-tables.h"
#pragma once

typedef struct UGGraph
{
    int Size;
    HashTable* hash;
}UGGraph;


UGGraph* UGCreate(int dataSize ,bool isString);
void UGAddVertex(UGGraph* graph, char* vertex);
void UGRemoveVertex(UGGraph* graph, char* vertex);
UGGraph* UGAddEdge(UGGraph* graph, char* vertex1, char* vertex2);
void UGRemoveEdge(UGGraph* graph, char* vertex1, char* vertex2);
HTItem UGGetAdjacent(UGGraph* graph, char* vertex);
HTItem UGShortestPath(UGGraph* graph, char* vertex1, char* vertex2);
void UGDestroy(UGGraph* graph);

//secondary functions that are used in the above ones
void printgraph(HashTable* hash);
UGGraph* CreateDataGraph(UGGraph* graph);
void recursiveDeleteAdjacentList(UGGraph* graph, char* vertex, node* item);
HTNode* findVertex(UGGraph* graph, char* vertex);