#include "graph.h"
#pragma once

typedef struct node{
    HTNode* adjacentNode;
    struct node* next;
}node;

typedef node HTItem;