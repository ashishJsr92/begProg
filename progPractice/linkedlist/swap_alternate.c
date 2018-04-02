/************************************************
 *This program swaps alternate nodes of the list.
 *
 * *********************************************/

#include<stdio.h>
#include "llist.h"

extern Node* createSortedList(int);
Node* swapAlternate(Node*);

int main()
{
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* list3 = NULL;

    list1 = createSortedList(3);
    list2 = createSortedList(1);
    list3 = createSortedList(8);

    printf("List1 : ");
    printList(list1);
    printf("After Swap : "); 
    printList(swapAlternate(list1));

    printf("\nList2 : ");
    printList(list2);
    printf("After Swap : "); 
    printList(swapAlternate(list2));


    printf("\nList3 : ");
    printList(list3);
    printf("After Swap : "); 
    printList(swapAlternate(list3));

    printf("\nList4 : ");
    printList(NULL);
    printf("After Swap : "); 
    printList(swapAlternate(NULL));

    return 0;
}


Node* swapAlternate(Node* head)
{
    Node* front = NULL,*nextPtr = NULL, *temp = NULL;

    if(head == NULL)
        return NULL;

    front = head;
    nextPtr = head->next;

    while(nextPtr)
    {
        front->next = nextPtr->next;
        nextPtr->next = front;

        //For the very first swap the head pointer needs to be changed
        if(front == head){
            head = nextPtr;
        }
        else{
            temp->next = nextPtr;    
        }

        temp = front;
        front = front->next;
        if(front)
            nextPtr = front->next;
        else
            break;

    }

    return head;   
}


/*
Node* swapAlternate(Node* head)
{
    Node* ptr = head, * temp = NULL, *temp1= NULL;

    if((ptr == NULL) || (ptr->next == NULL))
        return ptr;

    while(ptr && (ptr->next)){

        if(ptr == head){
            ptr  = ptr->next->next;
            temp = head->next;
            head->next = NULL;
            temp->next = head;
            head= temp;            
        }
        else{
            temp = ptr;
            ptr= ptr->next->next;
            temp->next->next = temp;
            temp1 = temp->next;
            temp->next = head;
            head = temp1;
        }
    }

    if(ptr){
        ptr->next = head;
        head = ptr;
    }

    return head;
}
*/

/*
Node* swapAlternate(Node* head)
{
    Node* ptr = head, *temp = NULL, *temp1 = NULL;

    while((ptr != NULL) && (ptr->next != NULL)){

        temp = ptr->next->next;
        if(ptr == head){
            head = ptr->next;
            head->next = ptr;
            ptr->next = NULL;
        }
        else{
            ptr->next->next = ptr;
            temp1 = ptr->next;
            ptr->next = head;
            head = temp1;            
        }
        
        ptr = temp;    
    }

    if(ptr){
        ptr->next = head;
        head = ptr;
    }

    return head;
}
*/




