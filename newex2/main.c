#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// void integers() {
//     UGGraph* graph = UGCreate(sizeof(int), false);
//     UGAddVertex(graph, "foo");
//     UGAddVertex(graph, "goo");
//     UGAddVertex(graph, "hoo");
//     UGAddVertex(graph, "joo");
//     UGAddVertex(graph, "koo");
//     UGAddVertex(graph, "loo");

//     printf("number of vertexes is : %d \n", HTSize(graph->hash));

//     UGRemoveVertex(graph, "goo");

//     printf("number of vertexes is : %d \n", HTSize(graph->hash));


// }

// int main(void) {
//     integers();
//     return 0;
// }


int main(void)
{
    UGGraph* graph = UGCreate(sizeof(int), false);
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

    UGAddEdge(graph, "foo", "hoo");

    // // HTItem temp = malloc(sizeof(HTItem));
    // HTItem temp = UGGetAdjacent(graph, "foo");
    // if(temp != NULL)
    //     if(temp->adjacentNode == NULL)
    //         printf(" qeef \n");
    // UGDestroy(graph);
    return 0;
}