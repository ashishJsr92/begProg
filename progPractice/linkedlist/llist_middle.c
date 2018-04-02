/***************************************************
 *Finding middle of the list.
 *************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<llist.h>

Node* findMiddle(Node*);
extern Node* createList(int);

int main(int argc, char* argv[])
{
    Node* head = NULL, *mid = NULL;

    if(argc < 2){
        printf("Error : Provide number of elements to be kept in the list as command line input\n");
        return -1;
    }

    head = createList(atoi(argv[1]));
    mid = findMiddle(head);

    printList(head);
    printf("Middle value : %d\n\n",mid->info);

    return 0;
}

Node* findMiddle(Node* head)
{
    Node* ptr1 = NULL, *ptr2 = NULL;


    if(head == NULL){
        return NULL;
    }

    if( (head->next == NULL) || (head->next->next == NULL)){
        return NULL;
    }

    ptr1 = ptr2= head;

    while(ptr1 && ptr2){

        if(ptr2->next == NULL){
            break;
        }
        else{
            ptr2 = ptr2->next->next;
            ptr1 = ptr1->next;
        }
    }
    
    return ptr1;
}
