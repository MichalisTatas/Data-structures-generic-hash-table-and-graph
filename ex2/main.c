#include<stdio.h>
#include "modules.h"

int main(void)
{
    Graph* graph;

    graph = UGCreate(7);

    UGAddVertex(graph, "foo");
    UGAddVertex(graph, "goo");
    UGAddVertex(graph, "poo");
    UGAddVertex(graph, "hoo");
    UGAddVertex(graph, "koo");
    UGAddVertex(graph, "loo");
    UGAddVertex(graph, "doo");
    UGAddVertex(graph, "boo");

    UGAddEdge(graph, "foo", "loo");
    UGAddEdge(graph, "foo", "boo");
    UGAddEdge(graph, "foo", "goo");
    UGAddEdge(graph, "foo", "hoo");
    UGAddEdge(graph, "hoo", "boo");
    UGAddEdge(graph, "hoo", "goo");
    UGPrint(*graph);

    printf("\nRemoving edge loo, foo \n");
    UGRemoveEdge(graph, "loo", "foo");
    UGPrint(*graph);
    
    printf("\nRemoving vertex foo \n");
    UGRemoveVertex(graph, "foo");
    UGPrint(*graph);

    printf("\nRemoving vertex koo \n");
    UGRemoveVertex(graph, "koo");
    UGPrint(*graph);

    Vertex* vertex = UGGetAdjacent(graph, "hoo");
    printf("\nAdjacent list is : ");
    while(vertex != NULL)
    {
        printf("%s  ", vertex->item);
        vertex = vertex->next;
    }

    UGDestroy(graph);
    UGPrint(*graph);

    return 0;
}