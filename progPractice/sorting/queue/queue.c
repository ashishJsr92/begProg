#include"queue.h"
#include<stdlib.h>

void enqueue(Queue* q, int info)
{
    if(q == NULL)
        return;

    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->info = info;
    ptr->next = NULL;

    if((q->front == NULL) && ( q->rear == NULL)){
        q->rear = q->front = ptr;
    }
    else{
        (q->rear)->next = ptr;
        (q->rear) = (q->rear)->next;
    }

    (q->size)++;
}

int dequeue(Queue* q)
{
    Node* temp = NULL;
    int val = 0;

    if(q == NULL)
        return -1;

    if(q->front == NULL)
        return -1;

    temp = q->front;
    q->front = (q->front)->next;
    if(q->front == NULL)
        q->rear = NULL;

    temp->next = NULL;
    val = temp->info; 
    free(temp);
    (q->size)--;

    return val;
}
