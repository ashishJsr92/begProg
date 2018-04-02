#include<stdlib.h>
#include"stack.h"

int top(Stack* st)
{
    if(st == NULL)
        return -1;

    return (st->top->info);
}

void push(Stack* st, int info)
{
    Node* ptr = NULL;

    if(st == NULL)
        return ;

    ptr = (Node*)malloc(sizeof(Node));
    ptr->info = info;
    ptr->next = NULL;

    if(st->top == NULL){
        st->top = ptr;
    }
    else{
        ptr->next = st->top;
        st->top = ptr;
    }

}

int pop(Stack* st)
{
    if(st == NULL)
        return -1;

    int val = 0;
    Node* temp = NULL;

    if(st->top == NULL)
        return -1;

    temp = st->top;
    st->top = (st->top)->next;

    val = temp->info;
    temp->next = NULL;
    free(temp);

    return val;
}

