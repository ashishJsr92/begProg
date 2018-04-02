#include<stdio.h>

typedef struct node
{
    int info;
    struct node* next;
}Node;

void enqueue(Node** front,Node** rear, int value);
void dequeue(Node** front, Node** rear, int* value);

