#include<stdio.h>
#include<llist.h>

void printList(Node* head)
{
    while(head != NULL){
        printf("<%d> ",head->info);
        head  = head->next;
    }
    printf("\n");
}
