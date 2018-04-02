/*********************************************
 *Remove duplicates from a string such that no 
 *adjacent characters are same.
 * ******************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char info;
    struct node* next;
}Node;


typedef struct stack
{
    Node* top;
}Stack;


void removeDuplicates(char* str);
void push(Stack*, char);
int pop(Stack*);
int top(Stack*);

int main()
{
    //char str[] = "MISSSSIPPI";
    char str[] = "MIIP";
    printf("Original : <%s>\n",str);
    removeDuplicates(str);
    printf("Later    : <%s>\n",str);

    return 0;
}

void push(Stack* st, char val)
{
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->info = val;
    ptr->next = NULL;

    if(st->top == NULL)
        st->top = ptr;
    else{
        ptr->next = st->top;
        st->top = ptr;
    }
}

int pop(Stack* st)
{
    if((st == NULL) || (st->top == NULL))
        return ' ';

    int val = 0;
    Node* temp = st->top;
    val = st->top->info;

    st->top = st->top->next;
    temp->next = NULL;

    free(temp);
    return val;
}

int top(Stack* st)
{
    if((st == NULL) || (st->top == NULL))
        return ' ';
    else
        return st->top->info;
}

void removeDuplicates(char* str)
{
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->top = NULL;

    int i = 0, len = strlen(str), count = 0;
    char ch = ' ';

    while( i < len){

        ch = top(st);
        if((ch == ' ') || (ch != str[i])){
            push(st,str[i]);
            count++;
            i++;
        }
        else{
            while(str[i] == ch)
                i++;
            pop(st);
            count--;
        } 
    }
    
    str[count] = '\0';
    while(count > 0){
        str[--count] = pop(st);
    }

}
