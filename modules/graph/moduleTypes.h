#pragma once
typedef struct Vertex Vertex;

typedef struct Node
{
    Vertex* vertex;
    struct Node* next; 
}Node;

struct Vertex
{
    char* item;
    Node* adjacent_list;
    struct Vertex* next;
};

typedef struct Graph
{
    int size;
    Vertex* list;
}Graph;