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

void printgraph(HashTable* hash) {
    HTNode* temp;
    HTItem mike;
    for(int i=0; i<hash->maxSize; i++) {
         temp = hash->array[i];
         if(temp != NULL)
         {
            printf("%s -->", (char*)temp->key);
            if(temp->item != NULL) {
                // printf(" %s ", (char*)temp->item->adjacentNode->key);
                mike = temp->item;
                while(mike != NULL) {
                    printf(" %s -->", (char*)mike->adjacentNode->key);
                    mike = mike->next;
                }
            }
            printf("\n");
         }
    }
}





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

    printf("number of vertexes is : %d \n\n", HTSize(graph->hash));

    UGRemoveVertex(graph, "goo");

    printf("number of vertexes after deletion is : %d \n\n", HTSize(graph->hash));

    UGAddEdge(graph, "foo", "hoo");
    UGAddEdge(graph, "foo", "loo");
    UGAddEdge(graph, "joo", "koo");


    printgraph(graph->hash);

    UGRemoveEdge(graph, "hoo", "foo");

    printf("\nRemoving edge between foo and loo : \n\n");

    printgraph(graph->hash);

    printf("\nRemoving vertex loo : \n\n");

    UGRemoveVertex(graph, "loo");

    printgraph(graph->hash);
    // // HTItem temp = malloc(sizeof(HTItem));
    // HTItem temp = UGGetAdjacent(graph, "foo");
    // if(temp != NULL)
    //     if(temp->adjacentNode == NULL)
    //         printf(" qeef \n");
    // UGDestroy(graph);
    return 0;
}
