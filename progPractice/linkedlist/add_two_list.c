#include<stdio.h>
#include<stdlib.h>
#include<llist.h>

int findSize(Node*);
Node* createList(int size);
void  printList(Node* ptr);
Node* addList(Node*, Node*);
Node* add(Node*, Node*);

int main()
{
    int n1 = 0, n2 = 0;
    Node* num1 = NULL, *num2 = NULL;

    printf("Enter number of digits in 1st number : ");
    scanf("%d",&n1);

    printf("Enter number of digits in 2nd number : ");
    scanf("%d",&n2);

    num1 = createList(n1);
    num2 = createList(n2);

    printf("1st Number : ");
    printList(num1);

    printf("\n2nd Number : ");
    printList(num2);

    printf("\nSummation : ");
    printList(addList(num1,num2));
    printf("\n");

    return 0;
}

Node* createList(int size)
{
    Node* head = NULL, *ptr = NULL, * temp = NULL;
    int i = 1;

    while(i <= size){
        temp = (Node*)malloc(sizeof(Node));
        temp->info = (rand() % 10);
        temp->next = NULL;

        if(head == NULL){
            head = ptr = temp;
        }
        else{
            ptr->next = temp;
            ptr = temp;
        }
        i++;
    }

    return head;
}

void printList(Node* head)
{
    while(head != NULL){
        printf("%d",head->info);
        head = head->next;
    }
    printf("\n");
}

int findSize(Node* head)
{
    int size = 0;
    while(head != NULL){
        size++;
        head = head->next;
    }
    return size;
}

Node* addList(Node* num1, Node* num2)
{
    if(num1 == NULL)
        return num2;

    if(num2 == NULL)
        return num1;

    Node* result = NULL, *temp = NULL,*temp1 = NULL, *temp2 = NULL, *curr = NULL, * curr2 = NULL, *res = NULL, *tr = NULL;
    int i = 1, size1 = 0, size2 = 0, sizeDiff = 0, carry = 0;

    size1 = findSize(num1);
    size2 = findSize(num2);
   
    sizeDiff = (size1 >= size2) ? (size1 - size2) : (size2 - size1);
     
    temp1 = (size1 >= size2) ? num1 : num2;
    temp2 = (size1 >= size2) ? num2 : num1;

    temp = temp1;
    while(i <= sizeDiff){
        temp = temp->next;
        i++;
    }

    result = add(temp, temp2);
    
    carry = result->info / 10;
    result->info = result->info % 10;

    
    if(sizeDiff != 0){

        i = sizeDiff;
        while(i > 0){
            curr = temp1;
            while(curr->next != temp){
                curr = curr->next; 
            }
            temp = curr;
    
            res = (Node*)malloc(sizeof(Node));
            res->info = curr->info + carry;
            res->next = result;
            result = res;
            i--;
	    carry = result->info / 10;
	    result->info = result->info % 10;
        }
    }
    
    if(carry != 0){
        res = (Node*)malloc(sizeof(Node));
        res->info = carry;
        res->next = result;
        result = res;
    }

    return result;
}

Node* add(Node* num1, Node* num2)
{
    int val = 0, carry = 0;
    Node* result = NULL;
    Node* temp = NULL;

    if((num1 == NULL) && (num2 == NULL)){
        return NULL;
    }
    else{
        temp = add(num1->next, num2->next);
    }

    if(temp != NULL){
	carry = temp->info / 10;
	temp->info = temp->info % 10;
    }

    val = num1->info + num2->info + carry;
    result = (Node*)malloc(sizeof(Node));
    result->info = val;
    result->next = temp;

    return result;
}


