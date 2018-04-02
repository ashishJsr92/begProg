#include<stdio.h>

#ifndef __NODE
#define __NODE
typedef struct node
{
    int info;
    struct node* next;
}Node;
#endif

typedef struct qu
{
    Node* front;
    Node* rear;
    int   size;
}Queue;

void enqueue(Queue*, int info);
int  dequeue(Queue*);
