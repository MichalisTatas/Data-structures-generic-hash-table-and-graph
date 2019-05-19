#include "moduleTypes.h"

Graph* UGCreate(int n);
void UGAddVertex(Graph*graph, char* vertex);
void UGRemoveVertex(Graph* graph, char* vertex);
void UGAddEdge(Graph* graph, char* vertex1, char* vertex2);
void UGRemoveEdge(Graph* graph, char* vertex1, char* vertex2);
Vertex* UGGetAdjacent(Graph* Graph, char* vertex);
Vertex* UGShortestPath(Graph* graph, char* vertex1, char* vertex2);
void UGDestroy(Graph* graph);

void UGPrint(Graph graph);
void VisitNodes(Graph* graph, char* vertex, Node* node);
void destroy(Graph* graph, Vertex* node);