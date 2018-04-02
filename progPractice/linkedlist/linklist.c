/****************************************************
 *Program to reverese a linked list.
 *
 * *************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
}Node;

Node* reverseList(Node* head);
void printNode(Node* head);

int main()
{
    Node* head = NULL, *temp = NULL, *ptr = NULL; 
    int i = 1;

    while(i <= 5){

        temp = (Node*) malloc(sizeof(Node));
        temp->value = i;
        temp->next = NULL;

        if(head == NULL){
            head = ptr = temp;
        }
        else{
            ptr->next = temp;
            ptr= ptr->next;
        }

        i++;
    }
    
    printNode(head);
    head = reverseList(head);
    printNode(head);

    return 0;
}


Node* reverseList(Node* head)
{
    Node* ptr = NULL, *prev = NULL;
    if(head == NULL)
       return NULL;

    ptr = head->next;
    prev = head;

    while(ptr != NULL){

        if(prev == head){
            head = head->next;
            prev->next = NULL;
            ptr = ptr->next;
            head->next = prev;
        }
        else{
            prev = head;
            head = ptr;
            ptr = ptr->next;
            head->next = prev;
        }
    }

    return head;
}


void printNode(Node* head){

    if(head == NULL)
        return;

    while(head != NULL){

        printf("<%d> ",head->value);
        head = head->next;
    }
    printf("\n");
}







