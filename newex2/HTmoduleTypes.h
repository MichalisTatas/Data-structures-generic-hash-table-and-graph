#include <stdbool.h>

typedef struct node {     //this is the struct used as HTItem to create the graph
    struct HTNode* adjacentNode;
    struct node* next;
} node;

typedef struct data {     //keeps the data for shortest path function  
    node* parent;
    bool visited;
    int dist;
} data;

typedef void* HTItem;     //is void* so that it can point to any type