#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(void)
{
    UGGraph* graph = UGCreate();
    graph->Size = 10;
    graph->hash->maxSize = 10;

    UGAddVertex(graph, "foo");
    UGAddVertex(graph, "goo");
    UGAddVertex(graph, "hoo");
    UGAddVertex(graph, "joo");
    UGAddVertex(graph, "koo");
    UGAddVertex(graph, "loo");

    printf("number of vertexes is : %d \n", HTSize(graph->hash));

    UGRemoveVertex(graph, "goo");

    printf("number of vertexes after deletion is : %d \n", HTSize(graph->hash));

    UGAddEdge(graph, "foo", "loo");

    // HTItem temp = malloc(sizeof(HTItem));
    HTItem temp = UGGetAdjacent(graph, "foo");
    if(temp != NULL)
        if(temp->adjacentNode == NULL)
            printf(" qeef \n");
    UGDestroy(graph);
    return 0;
}