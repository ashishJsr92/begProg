/*************************************************
 *Check for palindrome
 * **********************************************/
#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    char info;
    struct node* next;
}Node;

Node* createList(char* str);
int isPalindrome(Node* , Node*);

int main()
{
    Node* head = NULL;
    char str[200];
    int flag = 0;

    printf("Enter the word : ");
    scanf("%s",str);

    head = createList(str);
    flag = isPalindrome(head,head);

    if(flag){
        printf("It's a Palindrome\n");
    }
    else{
        printf("It's not a Palindrome\n");
    }

    return 0;
}

Node* createList(char* str)
{
    Node* head = NULL, * ptr = NULL, * temp = NULL;
    int i = 0;

    if(str == NULL){
        return NULL;
    }

    while(str[i]){

        temp = (Node*)malloc(sizeof(Node));
        temp->info = str[i];
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

    return head;
}


int isPalindrome(Node* head , Node* ptr)
{
    int ret = 0;
    
    if(ptr == NULL){
        return -1;
    }
    else{
        ret = isPalindrome(head,ptr->next);
        if(ret == 0){
            return 0;
        }
    }

    Node* cmp = head;
    Node* temp = ptr;

    while(temp->next != NULL){
        temp = temp->next;
        cmp = cmp->next;
    }

    if(cmp->info == ptr->info){
        return 1;
    }
    else{
        return 0;
    }

}



