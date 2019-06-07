#include <stdlib.h>
#include <string.h>
#include <limits.h>
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
    HTItem temp = NULL;                             
    graph->hash = HTInsert(graph->hash, vertex, temp);
}

void recursiveDeleteAdjacentList(UGGraph* graph, char* vertex, node* item) //destroys the adjacent list of a node recursively
{
    if(item == NULL)
        return;
    recursiveDeleteAdjacentList(graph, vertex, item->next);
    UGRemoveEdge(graph, vertex, item->adjacentNode->key);
}

void UGRemoveVertex(UGGraph* graph, char* vertex)
{
    HTNode* vertex1pointer = findVertex(graph, vertex);
    recursiveDeleteAdjacentList(graph, vertex, vertex1pointer->item);   
    HTRemove(graph->hash, vertex);
}

HTNode* findVertex(UGGraph* graph, char* vertex)       //returns pointer to vertex in the hash table
{
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
    HTNode* vertex1pointer = malloc(sizeof(HTNode)); 
    vertex1pointer = findVertex(graph, vertex1);    //pointer to vertex1 in the hash table
    
    HTNode* vertex2pointer = malloc(sizeof(HTNode)); 
    vertex2pointer = findVertex(graph, vertex2);    //pointer to vertex2 in the hash table
    
    // first insert vertex2 in the adjacent list of vertex1
    
    node* pitem;
    pitem = vertex1pointer->item;

    if(pitem != NULL) {
        while(pitem->next != NULL)
            pitem = pitem->next;
        pitem->next = malloc(sizeof(HTItem));
        pitem->next->adjacentNode = vertex2pointer;
        pitem->next->next = NULL; 
    }   
    else {
        vertex1pointer->item = malloc(sizeof(HTItem*));
        pitem = vertex1pointer->item;
        pitem->adjacentNode = malloc(sizeof(HTNode));
        pitem->adjacentNode = vertex2pointer;
        pitem->next = NULL;
    } 

    // second insert vertex1 int the adjacent list of vertex2
    
    node* pitem1  = malloc(sizeof(HTItem));
    pitem1 = vertex2pointer->item;

    if(pitem1 != NULL) {
        while(pitem1->next != NULL)
            pitem1 = pitem1->next;
        pitem1->next = malloc(sizeof(HTItem));
        pitem1->next->adjacentNode = vertex1pointer;
        pitem1->next->next = NULL; 
    }   
    else {
        vertex2pointer->item = malloc(sizeof(HTItem*));
        pitem1 = vertex2pointer->item;
        pitem1->adjacentNode = malloc(sizeof(HTNode));
        pitem1->adjacentNode = vertex1pointer;
        pitem1->next = NULL;
    }
    
    return graph;
}

void UGRemoveEdge(UGGraph* graph, char* vertex1, char* vertex2)
{
    HTNode* temp1 = findVertex(graph, vertex1);
    HTNode* temp2 = findVertex(graph, vertex2);
    node* fast = malloc(sizeof(node));
    node* slow = malloc(sizeof(node));

    slow = temp1->item;
    if(slow->next == NULL) {
        temp1->item = NULL;
        free(slow);
    }
    else if(!strcmp(slow->adjacentNode->key, vertex2)) {
        temp1->item = slow->next;
        free(slow);
    }
    else {
        fast = slow->next;
        while(strcmp(fast->adjacentNode->key, vertex2)) {
            slow = fast->next;
            fast = fast->next;
        }
        slow->next = fast->next;
        free(fast);
    }

    slow = temp2->item;
    if(slow->next == NULL) {
        temp2->item = NULL;
        free(slow);
    }
    else if(!strcmp(slow->adjacentNode->key, vertex1)) {
        temp2->item = slow->next;
        free(slow);
    }
    else {
        fast = slow->next;
        while(strcmp(fast->adjacentNode->key, vertex1)) {
            slow = fast->next;
            fast = fast->next;
        }
        slow->next = fast->next;
        free(fast);
    }
}

HTItem UGGetAdjacent(UGGraph* graph, char* vertex)
{
    HTItem temp = malloc(sizeof(HTItem));

    HTGet(graph->hash, vertex, &temp);

    return temp;
}

UGGraph* DuplicateGraphWithoutEdges(UGGraph* graph, char* source)           //copies the given graph to a new one and returns it
{
    UGGraph* DataGraph = UGCreate(sizeof(int), false);
    
    HTNode* vertexptr;

    data* vertexData = malloc(sizeof(data));
    vertexData->visited = false;
    vertexData->parent = NULL;
    vertexData->dist = INT_MAX;
    
    data* sourceData = malloc(sizeof(data));
    sourceData->visited = false;
    sourceData->parent = NULL;
    sourceData->dist = 0;

    for(int i=0; i<graph->hash->maxSize; i++) {

        vertexptr = graph->hash->array[i];
        if(vertexptr != NULL) {
            if(strcmp(vertexptr->key, source) == 0)
                HTInsert(DataGraph->hash, vertexptr->key, sourceData);
            else
                HTInsert(DataGraph->hash, vertexptr->key, vertexData);

            if(vertexptr->next != NULL) {
                while(vertexptr != NULL) {
                    if(strcmp(vertexptr->key, source) == 0)
                        HTInsert(DataGraph->hash, vertexptr->key, sourceData);
                    else
                        HTInsert(DataGraph->hash, vertexptr->key, vertexData);
                    vertexptr = vertexptr->next;
                }
            }
        }
    }

    // free(vertexData);
    // free(sourceData);
 
    return DataGraph;
}

HTNode* VertexWithMinDist(UGGraph* graph, char* destination)
{                   
    HTNode* temp;
    data* tempData = malloc(sizeof(data));
    HTNode* returnNode = NULL;
    int minDist = INT_MAX;

    for(int i=0; i<graph->hash->maxSize; i++) {
        temp = graph->hash->array[i];
        if(temp != NULL) {

            tempData = temp->item;
            if(tempData->visited == false) {
                if(tempData->dist < minDist) {
                    // returnNode = temp;
                    minDist = tempData->dist;
                }
            }

            if(temp->next != NULL) {
                while(temp != NULL) {
                    tempData = temp->item;
                    if(tempData->dist < minDist && tempData->visited == false) {
                        // returnNode = temp;
                        minDist = tempData->dist;
                    }
                        temp = temp->next;
                }
            }
        }
    }    







    for(int i=0; i<graph->hash->maxSize; i++) {
            temp = graph->hash->array[i];
            if(temp != NULL) {

                tempData = temp->item;
                    if(tempData->dist == minDist) {
                if(tempData->visited == false) {


                        // if(temp == NULL) 
                        //     return NULL;

                        
                        tempData->visited = true;
                        

                        return temp;

                    }
                }

                if(temp->next != NULL) {
                    while(temp != NULL) {
                        tempData = temp->item;
                        if(tempData->dist < minDist && tempData->visited == false) {
                            

                            // if(temp == NULL) 
                            // return NULL;

                            
                            tempData->visited = true;
                            

                            return temp;
                        }
                            temp = temp->next;
                    }
                }
            }
        }    









        return NULL;

    // tempData = returnNode->item;
    // tempData->visited = true;
    // returnNode->item = tempData;

    // return returnNode;
}
void printme(HashTable* hash) {
    HTNode* temp;
    data* mike;
    for(int i=0; i<hash->maxSize; i++) {
         temp = hash->array[i];
         if(temp != NULL)
         {
             mike = temp->item;
            printf("%d -->", mike->dist);
            if(mike->visited == true)
                printf("             visited true    ");
            else
                printf("             visited false    ");
            // if(temp->item != NULL) {
                // printf(" %s ", (char*)temp->item->adjacentNode->key);
                // mike = temp->item;
                // while(mike != NULL) {
                //     printf(" %s -->", mike->adjacentNode->key);
                //     mike = mike->next;
                // }
            // }
            printf("\n");
         }
    }
}

HTItem UGShortestPath(UGGraph* graph, char* source, char* destination)
{
    //first i need to create a graph with the same
    //keys but with the struct data as HTItem
    UGGraph* DataGraph = DuplicateGraphWithoutEdges(graph, source); 
    
    bool found = false;
    int alt;

    HTNode* u;
    data* uData;
    
    HTNode* graphNode;
    node* graphAdjacentList;

    HTNode* DataGraphNode;
    data* DataGraphData;

    while(found == false) {

printme(DataGraph->hash);
        u = VertexWithMinDist(DataGraph, destination);
printme(DataGraph->hash);

        if(u == NULL) {
            printf("error node with min value is null\n");
            return NULL;
        }

        uData = u->item;
// printf("I AM HERA IKN BVETWEEN \n");
        // uData->visited = true;

        printf("%s : %d \n ", u->key, uData->dist);

        if(strcmp(u->key, destination) == 0)
            found = true;
        
        if(found == false) {

            graphNode = findVertex(graph, u->key);  //u in graph's hash table
            graphAdjacentList = graphNode->item;    //list of thew neighbors of u
        
            while(graphAdjacentList != NULL) {

                DataGraphNode = findVertex(DataGraph, graphAdjacentList->adjacentNode->key);  //neighbor of u in DataGraph
                DataGraphData = DataGraphNode->item;   //data of neighbor of u 
 
                if(DataGraphData->visited == false) {
                    printf("POUTRS \n");
                    alt = uData->dist + 1;
                    if(alt < DataGraphData->dist) {
                        DataGraphData->dist = alt;
                        DataGraphData->parent = u;
                    }
                }
                graphAdjacentList = graphAdjacentList->next;
            }

        }
    }
    // UGDestroy(DataGraph);
    // return ?
}

void UGDestroy(UGGraph* graph)
{
    HTDestroy(graph->hash);
    free(graph);
}


























