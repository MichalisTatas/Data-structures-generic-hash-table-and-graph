#include <stdio.h>
#include "graph.h"

int main(void)
{
    UGGraph* graph = UGCreate();
    graph->Size = 20;
    graph->hash->maxSize = 20;

    UGAddVertex(graph, "foo");
    UGAddVertex(graph, "goo");
    UGAddVertex(graph, "hoo");
    UGAddVertex(graph, "joo");
    UGAddVertex(graph, "koo");
    UGAddVertex(graph, "loo");

    printf("number of vertexes is : %d \n", HTSize(graph->hash));

    UGRemoveVertex(graph, "goo");

    printf("number of vertexes after deletion is : %d \n", HTSize(graph->hash));

    UGAddEdge(graph, "foo", "joo");

    HTItem temp = UGGetAdjacent(graph, "foo");
    if(temp->adjacentNode == NULL)
        printf("POUTSOS");
    return 0;
}