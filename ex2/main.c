#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void printgraph(HashTable* hash) {
    HTNode* temp;
    node* mike;
    for(int i=0; i<hash->maxSize; i++) {
         temp = hash->array[i];
         if(temp != NULL)
         {
            printf("%s -->", (char*)temp->key);
            if(temp->item != NULL) {
                // printf(" %s ", (char*)temp->item->adjacentNode->key);
                mike = temp->item;
                while(mike != NULL) {
                    printf(" %s -->", mike->adjacentNode->key);
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
    // graph->Size = 10;
    // graph->hash->maxSize = 10;

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

    UGRemoveEdge(graph, "foo", "hoo");

    printf("\nRemoving edge between foo and hoo : \n\n");

    printgraph(graph->hash);

    printf("\nRemoving vertex loo : \n\n");

    UGRemoveVertex(graph, "loo");

    printgraph(graph->hash);

    UGShortestPath(graph, "foo", "joo");

    UGDestroy(graph);
    return 0;
}
