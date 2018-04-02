#include"queue.h"
#include"stack.h"
#include<stdlib.h>

void reverseKValues(Queue*, int k);

int main()
{
    int count = 0, val = 0, k = 0;
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;

    printf("Enter the values into the queue (Enter -100 to exit)\n");
    printf("Value : ");
    scanf("%d",&val);
    
    while(val != -100)
    {
        enqueue(q,val);
        printf("Value : ");
        scanf("%d",&val);
        count++; 
    }
    count--;

    printf("\nNumber of elements to reverse : ");
    scanf("%d",&k);

    reverseKValues(q, k);

    printf("Queue : ");
    while((val = dequeue(q)) != -1){
        printf("%d - ",val);
    }

    printf("\n");

    return 0;
}

void reverseKValues(Queue* q, int k)
{
    int i = 1, val = 0;
    Stack* st = NULL;

    if((q == NULL) || (k <= 0))
        return;

    if(k > q->size){
        k = q->size;
    }

    st = (Stack*)malloc(sizeof(Stack));
    st->top = NULL;
    
    /*Dequeue and push into stack the first "K" elements*/
    while( i <= k){
        val = dequeue(q);
        //printf("** DEBUG : <Dequeue : %d>\n",val);
        push(st,val);
        i++;
    }

    /*Push stack elements into queue */
    while( (val = pop(st)) != -1){
        //printf("** DEBUG : <Enqueue : %d>\n",val);
        enqueue(q,val);
    }


    /*Dequeue and enqueue again rest other elements */    
    i = (q->size) - k;
    while(i > 0){
        enqueue(q, dequeue(q));
        i--;
    }
}

