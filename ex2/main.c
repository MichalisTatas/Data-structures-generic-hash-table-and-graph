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




    UGAddEdge(graph, "foo", "hoo");
    UGAddEdge(graph, "foo", "loo");
    UGAddEdge(graph, "joo", "koo");
    UGAddEdge(graph, "hoo", "joo");
    UGAddEdge(graph, "loo", "koo");
    UGAddEdge(graph, "hoo", "loo");
    UGAddEdge(graph, "foo", "goo");

    printgraph(graph->hash);

    printf("number of vertexes is : %d \n\n", HTSize(graph->hash));

    UGRemoveVertex(graph, "loo");

    printf("number of vertexes after  deletion is : %d \n\n", HTSize(graph->hash));

    printf("\nRemoving edge between foo and hoo : \n\n");
    
    UGRemoveEdge(graph, "foo", "hoo");

    printgraph(graph->hash);

    printf("\nRemoving vertex loo : \n\n");


    printgraph(graph->hash);

    // UGShortestPath(graph, "foo", "koo");

    UGDestroy(graph);
    return 0;
}
