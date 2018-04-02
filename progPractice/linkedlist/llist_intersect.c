/*******************************
 *Check if two lists intersect.
 * ****************************/

#include<stdio.h>
#include<stdlib.h>
#include<llist.h>

typedef struct stack
{
    Node* info;
    struct stack* next;
}Stack;

extern Node* createList(int);
Node* getIntersection(Node* , Stack*);
Stack* push(Stack* top, Node* temp);
Node* pop(Stack** top);

int main()
{
    Node* head1 = NULL, *head2 = NULL;
    Node* intersect = NULL;
    Stack* top = NULL;

    head1  = createList(20);
    head2  = head1->next->next;

    while(head2 != NULL){
        top = push(top,head2);
        head2 = head2->next;
    }

    intersect = getIntersection(head1, top);

    printf("Intersection point : <%d>\n", intersect->info);
    return 0;
}

Node* getIntersection(Node* head1, Stack* head2)
{
    if((head1 == NULL) || (head2 == NULL)){
        return NULL;
    }
    Node* intersect = NULL;

    if(head1->next != NULL){
        intersect = getIntersection(head1->next , head2);
        if(intersect != NULL){
            return ; 
        }
        

    }
    else{
        if(head1->info == pop(&head2)){
            return NULL;
        }
        else{
            
        }
    }
    


}

Stack* push(Stack* top,Node* ptr)
{
    Stack* temp = (Stack*)malloc(sizeof(Stack));
    temp->info = ptr;
    temp->next = NULL;

    if(top != NULL){
        temp->next = top;
    }

    return temp;
}


Node* pop(Stack** top)
{
    if((top == NULL) || (*top == NULL))
        return NULL;

    Node* val = (*top)->info;
    Stack* ptr = *top;
    *top = (*top)->next;
    ptr->next = NULL;
    free(ptr);

    return val;
}


