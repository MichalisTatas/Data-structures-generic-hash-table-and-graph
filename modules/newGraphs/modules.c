#include <stdlib.h>
#include <string.h>
#include "graph.h"

UGGraph* UGCreate(int dataSize ,bool isString)
{
    UGGraph* graph = malloc(sizeof(UGGraph));
    
    graph->hash = HTCreate(dataSize ,isString);
    graph->Size = 0;
    
    return graph;
}

void UGAddVertex(UGGraph* graph, char* vertex)
{
    HTItem temp = malloc(sizeof(HTItem));    
    graph->hash = HTInsert(graph->hash, vertex, temp);
}

void UGRemoveVertex(UGGraph* graph, char* vertex)
{
    HTRemove(graph->hash, vertex);   //how to remove it from any adjacent list
}

HTNode* findVertex(UGGraph* graph, char* vertex) {     //returns pointer to vertex in the hash table
    HTNode* vertexPosition = malloc(sizeof(HTNode));
    int index = HashFunction(vertex, graph->hash->maxSize);
    vertexPosition = graph->hash->array[index];

    if(graph->hash->array[index] == NULL) {
        printf("wrong string\n");
        return NULL;
    }
    if(vertexPosition->next == NULL)
        return vertexPosition;
    while(strcmp(vertexPosition->key, vertex) != 0)
        vertexPosition = vertexPosition->next;                           //finds vertex1 in the hash table
    return vertexPosition;
}

UGGraph* UGAddEdge(UGGraph* graph, char* vertex1, char* vertex2)
{
    HTNode* vertex1pointer = findVertex(graph, vertex1);    //pointer to vertex1 in the hash table
    HTNode* vertex2pointer = findVertex(graph, vertex2);    //pointer to vertex2 in the hash table
    
    printf("%s", vertex1pointer->key);
    printf("%s", vertex2pointer->key);
    //first insert vertex2 in the adjacent list of vertex1
    // HTItem pitem; // = malloc(sizeof(HTItem));
    // if(HTGet(graph->hash, vertex1, &pitem) == true) {
    //     // while(pitem->next != NULL)
    //     //     pitem = pitem->next;
    //     // // pitem->next = malloc(sizeof(HTItem));
    //     // pitem->next->adjacentNode = vertex2pointer;
    //     // pitem->next->next = NULL; 
    //     printf("geia");
    // }   
    // else {
    //     // vertex1pointer->item = malloc(sizeof(HTItem*));
    //     // vertex1pointer->item->adjacentNode = vertex2pointer;
    //     // vertex1pointer->item->next = NULL;
    // } 

    //second insert vertex1 int the adjacent list of vertex2
    
    // HTItem pitem1; // = malloc(sizeof(HTItem));
    // if(HTGet(graph->hash, vertex2, &pitem1) == true) {
    //     // while(pitem1->next != NULL)
    //     //     pitem = pitem1->next;
    //     // // pitem->next = malloc(sizeof(HTItem));
    //     // pitem1->next->adjacentNode = vertex1pointer;
    //     // pitem1->next->next = NULL; 
    //     printf("geia");
    // }   
    // else {
    //     // vertex2pointer->item = malloc(sizeof(HTItem*));
    //     vertex2pointer->item->adjacentNode = vertex1pointer;
    //     vertex2pointer->item->next = NULL;
    // }
    
    return graph;
}

// void UGRemoveEdge(UGGraph* graph, char* vertex1, char* vertex2)
// {
//     HTItem temp;

//     HTGet(graph->hash, vertex1, temp);
//     if(strcmp(temp->adjacentNode->item, vertex2) == 0)
//         if(temp->next == NULL)
//             temp = NULL;
//         else 
// }

HTItem UGGetAdjacent(UGGraph* graph, char* vertex)
{
    HTItem temp = malloc(sizeof(HTItem));

    HTGet(graph->hash, vertex, &temp);

    return temp;
}

void UGDestroy(UGGraph* graph)
{
    HTDestroy(graph->hash);
    free(graph);
}



























// // HTNode* adjacentnode;// = malloc(sizeof(HTNode));
//     HTItem temp;// = malloc(sizeof(HTItem));
//     int index;

//     //for the first vertex
//     //get his adjacent list and add at the end a pointer to vertex 2

//     // index = HashFunction(vertex2, graph->hash->maxSize);

//     // adjacentnode = graph->hash->array[index];       //find the vertex in the list of the array position since its a hash table
//     // while(strcmp(adjacentnode->key, vertex2) != 0)
//     //     adjacentnode = adjacentnode->next;
    
//     HTGet(graph->hash, vertex1, &temp);
    
//     if(temp != NULL)
//     {
//         while(temp->next != NULL)
//             temp = temp->next;
//         temp->next = malloc(sizeof(HTItem));
//         temp->next->adjacentNode = adjacentnode;
//         // temp->next->next = NULL;
//     }
//     else
//     {
//         printf("DSFDFS");
//         // temp = malloc(sizeof(HTItem));
//         // adjacentnode->item = malloc(sizeof(HTItem));
//         temp->adjacentNode = adjacentnode;
//         // temp->next = NULL;
//     }


//     //for the first vertex
//     //get his adjacent list and add at the end a pointer to vertex 2

//     // index = HashFunction(vertex1, graph->hash->maxSize);
//     // adjacentnode = graph->hash->array[index];       //find the vertex in the list of the array position since its a hash table
//     // while(strcmp(adjacentnode->key, vertex1) != 0)
//     //     adjacentnode = adjacentnode->next;
    
//     HTGet(graph->hash, vertex2, &temp);
    
//     if(temp != NULL)
//     {
//         while(temp->next != NULL)
//             temp = temp->next;
//         temp->next = malloc(sizeof(HTItem));
//         temp->next->adjacentNode = adjacentnode;
//         // temp->next->next = NULL;
//     }
//     else
//     {
//         // temp = malloc(sizeof(HTItem));
//         temp->adjacentNode = adjacentnode;
//         // temp->next = NULL;
//     }
//     return graph;