/**************************************************
 *Finding a loop in a linked list
 * ***********************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
}Node;

int findLoop(Node* head);

int main()
{
    Node* head = NULL, *ptr = NULL,*temp = NULL;
    int i = 1, hasLoop = 1;

    while(i <= 5){

        temp = (Node*) malloc(sizeof(Node));
        temp->value = i*1;
        temp->next = NULL;

        if(head == NULL){
            head = ptr = temp;
        }
        else{
            ptr->next = temp;
            ptr = ptr->next;
        }
        i++;
    }

    hasLoop = findLoop(head);
    
    if(hasLoop){
        printf("LinkedList has loop\n");
    }
    else
        printf("Doesn't have loop\n");
   
    ptr->next = head->next;
    hasLoop = findLoop(head);
    
    if(hasLoop){
        printf("LinkedList has loop\n");
    }
    else
        printf("Doesn't have loop\n");

    return 0;
}


int findLoop(Node* head)
{
    int hasLoop = 0;
    Node* back = NULL, *fwd = NULL;

    if(head == NULL)
        return 0;
    
    back = head;
    fwd = head->next;

    while( back && fwd){

        if(back ==fwd){
            hasLoop = 1;
            break ;
        }

        back = back->next;

        if(fwd->next){
            fwd = fwd->next->next;
        }
        else{
            fwd =fwd->next;
        }
    }

    return hasLoop;
}

