/*********************************************
 *Topological sort implementation
 * Flow : Program reads graph info from a file
 * and then does a topological sort over it.
 *
 * NOTE:  Graph has to be a DAG 
 * ******************************************/

#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

Node* topoSort(int **graph, int vertexCount);
void enqueueNode(int** graph, Node** front, Node** rear, int vertexCount, Node* result);
int isPartOfResult(Node* result, int vertex);
Node* insertIntoResult(Node* result, int vertex);


int main()
{
    int** graph = NULL;
    int i = 0, j = 0,vertexCount = 0, val = 0;
    FILE* fp = NULL;
    char ch = ' ';
    Node* result = NULL;

    fp = fopen("input.txt","r");
    if(fp == NULL){
        fprintf(stderr,"Unable to open the input file\n");
        return -1;
    }
   
    fscanf(fp,"%d",&vertexCount);
    ch = fgetc(fp);

    /** Allocating memory **/
    graph = (int**)malloc(sizeof(int*) * vertexCount);
    if(graph == NULL){
        fprintf(stderr, "Error: Memory insufficient\n");
        return -1;
    }

    for(i=0; i<vertexCount; i++){
        graph[i] = (int*)malloc(sizeof(int) * vertexCount);
    }

    i=0;

    /*Fetching graph info */
    //while(ch != EOF){
    while(i < vertexCount){
        for(j = 0; j< vertexCount; j++){
            fscanf(fp,"%d",&val);
            if(val != 0){
                graph[i][j] = 1;
            }
            else
                graph[i][j] = 0;

            ch = fgetc(fp);
        }
        i++;
    }

    /*printf("GRAPH -- \n");
    for(i=0; i< vertexCount; i++){
        for(j=0; j< vertexCount ; j++){
            printf("%d ",graph[i][j]); 
        }
        printf("\n");
    }*/

    result = topoSort(graph, vertexCount);
    while(result != NULL){
        if(result->next != NULL)
            printf("%d -> ",result->info);
        else
            printf("%d\n",result->info);

        result = result->next;
    }

    return 0;
}

void enqueueNode(int** graph, Node** front, Node** rear, int vertexCount, Node* result)
{
    int i = 0, j = 0, vertex = 1, indegree = 0;

    /*Find vertex with indegree "0" and push it in queue */
    for(vertex = 1; vertex <= vertexCount ; vertex++){

        if(isPartOfResult(result, vertex)){
            continue;
        }

        //printf("** DEBUG -- <%d>  " ,vertex);
        indegree = 0;
        for(i=1; i<=vertexCount ;i++){
            if(graph[i-1][vertex - 1] != 0)
                indegree++;
        }
        if(indegree == 0)
            enqueue(front,rear,vertex);
    }
    printf("\n");
}

int isPartOfResult(Node* result, int vertex)
{
    if(result == NULL)
        return 0;

    while((result) && (result->info != vertex)){
        result = result->next;
    }

    if(result == NULL)
        return 0;
    else
        return 1;
}

Node* insertIntoResult(Node* result, int vertex)
{
    Node* val = (Node*)malloc(sizeof(Node));
    Node* temp = result;

    val->info = vertex;
    val->next = NULL;

    if(result == NULL){
        result = val;
    }
    else{
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = val;
    }

    return result;
}

Node* topoSort(int** graph, int vertexCount)
{
    int i=0, vertex = 1, indegree = 0, count  = 0;
    Node* front = NULL, *rear = NULL, *result = NULL;

    enqueueNode(graph, &front, &rear, vertexCount, result);

    printf("\nTOPOLOGICAL SORT : \n");
    while(rear != NULL){
        dequeue(&front, &rear, &vertex);
        //printf("**DEBUG  - <Dequeue : %d>\n",vertex);

        result = insertIntoResult(result,vertex);
        
        for(i=0; i<vertexCount; i++)
            graph[vertex-1][i] = 0;

        enqueueNode(graph, &front, &rear, vertexCount, result);
        count++;
    }

    if(count != vertexCount){
        printf("\nCycle detected\n");
        return NULL;
    }

    return result;
}
