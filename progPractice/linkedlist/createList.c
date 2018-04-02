#include<stdio.h>
#include<stdlib.h>
#include<llist.h>


Node* createList(int size)
{
    Node* head = NULL, * ptr = NULL, *temp = NULL;
    int val = rand() % 500;
    int itr = 0;

    while(itr < size){

        temp = (Node*)malloc(sizeof(Node));
        temp->info = val;
        val = rand() % 500;
        temp->next = NULL;

        if(head == NULL){
            head = ptr = temp;
        }
        else{
            ptr->next = temp;
            ptr = ptr->next;
        }

        itr++;
    }

    return head;
}

