#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdbool.h"
#include "modules.h"
#include "queues.h"

Graph* UGCreate(int n)
{
    Graph* graph = malloc(sizeof(Graph));
    graph->list = NULL;
    graph->size = 0;
    return graph;
}

void UGAddVertex(Graph* graph, char* vertex)
{
    Vertex* temp;

    if(graph->list == NULL)
    {
        graph->list = malloc(sizeof(Vertex));
        graph->list->item = malloc((strlen(vertex)+1)*sizeof(char));
        strcpy(graph->list->item, vertex);
        graph->list->next = NULL;
        graph->list->adjacent_list = NULL;
    }
    else
    {
        temp = graph->list;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = malloc(sizeof(Vertex));
        temp->next->item = malloc((strlen(vertex)+1)*sizeof(char));
        strcpy(temp->next->item, vertex);
        temp->next->next = NULL;
        temp->next->adjacent_list = NULL;
    }
}

void UGAddEdge(Graph* graph, char* vertex1, char* vertex2)
{
    Vertex* curr1 = graph->list;
    Vertex* curr2 = graph->list;
    Node* temp1;
    Node* temp2;

    while(strcmp(curr1->item, vertex1))
        curr1 = curr1->next;
    while(strcmp(curr2->item, vertex2))
        curr2 = curr2->next;

    if(curr1->adjacent_list == NULL)
    {
        curr1->adjacent_list = malloc(sizeof(Node));
        curr1->adjacent_list->next = NULL;
        curr1->adjacent_list->vertex = curr2;
    }
    else
    {
        temp1 = curr1->adjacent_list;
        while(temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = malloc(sizeof(Node));
        temp1->next->next = NULL;
        temp1->next->vertex = curr2;
    }

    if(curr2->adjacent_list == NULL)
    {
        curr2->adjacent_list = malloc(sizeof(Node));
        curr2->adjacent_list->next = NULL;
        curr2->adjacent_list->vertex = curr1;
    }
    else
    {
        temp2 = curr2->adjacent_list;
        while(temp2->next != NULL)
            temp2 = temp2->next;
        temp2->next = malloc(sizeof(Node));
        temp2->next->next = NULL;
        temp2->next->vertex = curr1;
    }
}

void UGRemoveEdge(Graph* graph, char* vertex1, char* vertex2)
{
    Vertex* temp = graph->list;
    Node* fast;
    Node* slow;

    while(strcmp(temp->item, vertex1))
        temp = temp->next;
    fast = temp->adjacent_list;
    while(strcmp(fast->vertex->item, vertex2))
    {
        slow = fast;
        fast = fast->next;
    }
    if(fast == temp->adjacent_list)
        if(fast->next == NULL)
            temp->adjacent_list = NULL;
        else
        temp->adjacent_list = fast->next;
    else
        slow->next = fast->next;
    free(fast);

    temp = graph->list;
    while(strcmp(temp->item, vertex2))
        temp = temp->next;
    fast = temp->adjacent_list;
    slow = temp->adjacent_list;
    while(strcmp(fast->vertex->item, vertex1))
    {
        slow = fast;
        fast = fast->next;
    }
    if(fast == temp->adjacent_list)
        if(fast->next == NULL)
            temp->adjacent_list = NULL;
        else
        temp->adjacent_list = fast->next;
    else
        slow->next = fast->next;
    free(fast);
}

void VisitNodes(Graph* graph, char* vertex, Node* node)
{
    if(node == NULL)
        return;
    VisitNodes(graph, vertex, node->next);
    UGRemoveEdge(graph, vertex, node->vertex->item);
}

void UGRemoveVertex(Graph* graph, char* vertex)
{
    Vertex* fast = graph->list;
    Vertex* slow;
    while(strcmp(fast->item, vertex))
    {
        slow = fast;
        fast = fast->next;
    }

    VisitNodes(graph, vertex, fast->adjacent_list);
    if(fast == graph->list)
        if(fast->next == NULL)
            graph->list = NULL;
        else
            graph->list = fast->next;
    else
        slow->next = fast->next;
    free(fast->item);
    free(fast);
}

Vertex* UGGetAdjacent(Graph* Graph, char* vertex)
{
    Vertex* temp = Graph->list;
    Node* node;
    Vertex *list = NULL;
    Vertex *curr;
    
    while(strcmp(temp->item, vertex))
        temp = temp->next;
    node = temp->adjacent_list;
    
    while(node != NULL)
    {
        Vertex* last;

        if(list == NULL)
        {
            list = malloc(sizeof(Vertex));
            // strcpy(list->item, node->vertex->item);
            list->item=node->vertex->item;
            curr = list;
            list->adjacent_list = NULL;
        }
        else
        {
            last = malloc(sizeof(Vertex));
            // strcpy(last->item, node->vertex->item);
            last->item = node->vertex->item;
            last->adjacent_list = NULL;
            curr->next = last;
            curr = last;
        }
        node = node->next;
    }
    return list;
}

// Vertex* UGShortestPath(Graph* graph, char* vertex1, char* vertex2)
// {
//     typedef struct temp{                                 //to store the node and its parent
//         Vertex* node;
//         Vertex* parent;
//         bool visited;
//     }temp;
    
//     temp* array[graph->size];
//     Vertex* iterator = graph->list;
//     for(int i=0; i<graph->size; i++)
//     {
//         array[i] = malloc(sizeof(temp));
//         array[i]->node = iterator;
//         array[i]->parent = NULL;
//         array[i]->visited = false;
//         iterator = iterator->next;
//     }

//     Queue q;
//     InitializeQueue(&q);
//     Insert(array[0], &q);
    
// }

void destroy(Graph* graph, Vertex* node)
{
    if(node == NULL)                
        return;
    destroy(graph, node->next);
    UGRemoveVertex(graph, node->item);    
}

void UGDestroy(Graph* graph)
{
    destroy(graph, graph->list);                 //destroy the graph recursively     
}

void UGPrint(Graph graph)
{
    Vertex* curr;
    Node* temp;

    curr = graph.list;
    if(curr == NULL)
        printf("\nGraph is Empty\n");
    else
    {
        printf("\n");
        while(curr != NULL)
        {
            printf("%s -->", curr->item);
            temp = curr->adjacent_list;
            while(temp != NULL)
            {
                printf(" %s,", temp->vertex->item);
                temp = temp->next;
            }
            printf("\n");
            curr = curr->next;
        }
    }
}
