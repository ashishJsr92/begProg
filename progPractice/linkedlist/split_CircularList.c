#include<stdio.h>
#include<llist.h>

extern Node* createList(int);
Node* makeCircular(Node*);
void printCircular(Node* head);
Node* splitList(Node*);
extern void  printList(Node*);

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head3 = NULL;
    Node* head4 = NULL;
    Node* head1_2 = NULL, *head2_2 = NULL, *head3_2 = NULL,* head4_2 = NULL;

    head1 = makeCircular(createList(5));
    head2 = makeCircular(createList(1));
    head3 = makeCircular(createList(8));
    head4 = makeCircular(createList(2));

    printf("** HEAD 1 -- \n");
    printCircular(head1);
    head1_2 = splitList(head1);
    printf("** FIRST HALF -- ");
    printList(head1);
    printf("** SECOND HALF -- ");
    printList(head1_2);
    
    printf("\n\n** HEAD 2 -- \n");
    printCircular(head2);
    head2_2 = splitList(head2);
    printf("** FIRST HALF -- ");
    printList(head2);
    printf("** SECOND HALF -- ");
    printList(head2_2);

    printf("\n\n** HEAD 3 -- \n");
    printCircular(head3);
    head3_2 = splitList(head3);
    printf("** FIRST HALF -- ");
    printList(head3);
    printf("** SECOND HALF -- ");
    printList(head3_2);
    

    printf("\n\n** HEAD 4 -- \n");
    printCircular(head4);
    head4_2 = splitList(head4);
    printf("** FIRST HALF -- ");
    printList(head4);
    printf("** SECOND HALF -- ");
    printList(head4_2);
    
    return 0;
}

void printCircular(Node* head)
{
    if(head == NULL)
        return;

    Node* ptr = head->next;
    printf("%d ",head->info);
    while(ptr != head){
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

Node* makeCircular(Node* head)
{
    if(head == NULL)
        return NULL;

    Node* ptr = head;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    ptr->next = head;
    return head;
}

Node* splitList(Node* head)
{
    if(head == NULL)
        return NULL;

    if(head->next == head){
        head->next = NULL;
        return NULL;
    }

    Node* slowPtr = head, *temp = NULL;
    Node* fastPtr = head->next;

    while( (fastPtr != head) && (fastPtr->next != head) ){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    temp = slowPtr->next;
    slowPtr->next = NULL;

    if(fastPtr->next == head){
        fastPtr->next = NULL;
        return temp;
    }
    else{
        fastPtr = temp;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = NULL;
        return fastPtr;
    }

}


