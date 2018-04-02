#include<stdio.h>

#ifndef __NODE
#define __NODE
typedef struct node
{
    int info;
    struct node* next;
}Node;
#endif

typedef struct stack
{
    Node* top;
}Stack;

int top(Stack*);
int pop(Stack*);
void push(Stack*, int);
