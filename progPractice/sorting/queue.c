/*****************************
 *Queue implementation in C
 * **************************/

#include<stdio.h>
#include"queue.h"
#include<stdlib.h>

void enqueue(Node** front,Node** rear, int value)
{
    Node* val = (Node*)malloc(sizeof(Node));
    val->info = value;
    val->next = NULL;

    if(*rear == NULL){
        *front = *rear = val;
    }
    else{
        (*rear)->next = val;
    }
}

void dequeue(Node** front, Node** rear, int* value)
{
    if(*front == NULL)
        return;

    Node* temp = *front;
    *front = (*front)->next;

    *value = temp->info;
    temp->next = NULL;
    free(temp);

    if(*front == NULL)
        *rear = NULL;
}



