#include "moduleTypes.h"


typedef struct temp{                               
    Vertex* node;
    Vertex* parent;
    bool visited;
}temp;

typedef temp ItemType;

typedef struct QueueNodeTag {
                     ItemType Item;
                     struct QueueNodeTag *Link;
                } QueueNode;

typedef struct {
                    QueueNode *Front;
                    QueueNode *Rear;
               } Queue;

void InitializeQueue(Queue *Q);
int Empty(Queue *Q);
int Full(Queue *Q);
void Insert(ItemType R, Queue *Q);
ItemType Remove(Queue *Q);