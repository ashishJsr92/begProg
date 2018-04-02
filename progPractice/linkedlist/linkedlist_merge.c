/********************************
 *Merge "N" linkedlist.
 * *****************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
}Node;

Node* mergeTwoList(Node* list1, Node* list2);
void printList(Node* ptr);


int main()
{
    int i = 1, val1 = 1, val2 = -5;
    Node* list1 = NULL, *list2 = NULL, *temp = NULL, *temp2 = NULL, *ptr1= NULL, *ptr2 = NULL;
    Node* newList = NULL;

    while( i <= 5){

        temp = (Node*)malloc(sizeof(Node));
        temp->value = val1;
        val1 = val1 + 5;
        temp->next = NULL;

        temp2 = (Node*)malloc(sizeof(Node));
        temp2->value = val2;
        val2 = val2 + 7;
        temp2->next = NULL;

        if(list1 == NULL){
            list1 = ptr1 = temp ;
        }
        else{
            ptr1->next = temp;
            ptr1 = ptr1->next;
        }


        if(list2 == NULL){
            list2 = ptr2 = temp2;
        }
        else{
            ptr2->next = temp2;
            ptr2 = ptr2->next;
        }
        i++;
    }

    printList(list1);
    printList(list2);

    newList = mergeTwoList(list1, list2);
    printList(newList);



    return 0;
}

void printList(Node* ptr)
{
    printf("***************** LIST *******************\n");
    while(ptr){
        printf("<%d> ",ptr->value);
        ptr =ptr->next;
    }
    printf("\n\n");
}


Node* mergeTwoList(Node* list1, Node* list2)
{
    Node* ptr1 = NULL, *ptr2 = NULL, *newList = NULL, *temp = NULL, *tr = NULL;

    if(list1 == NULL)
        return list2;

    if(list2 == NULL)
        return list1;

    ptr1 = list1;
    ptr2 = list2;

    while( (ptr1 != NULL) && (ptr2 != NULL)){

        if(ptr1->value <= ptr2->value){
            temp = ptr1;
            ptr1 = ptr1->next;
            temp->next = NULL;
        }
        else{
            temp = ptr2;
            ptr2 = ptr2->next;
            temp->next = NULL;
        }

        if(newList == NULL){
            newList = tr = temp;
        }
        else{
            tr->next = temp;
            tr = tr->next;
        }
    }


    if(ptr1){
        temp = ptr1;
    }
    else{
        temp = ptr2;
    }

    tr->next = temp;

    return newList;
}




