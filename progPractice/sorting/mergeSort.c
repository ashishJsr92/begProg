/***************************************************
 * Program to implement merge sort in an array
 *
 * ************************************************/

#include<stdio.h>
#include<stdlib.h>

void mergeSort(int arr[], int high);
void printArray(int arr[], int count);


int main()
{
    int arr[300] = {0};
    int i = 0 ,val = 0, count = 0;
    printf("Enter number of elements : ");
    scanf("%d",&count);
    printf("\n");

    for(i=0; i<count ; i++){ 
        printf("Value : ");
        scanf("%d",&val);
        arr[i] = val;
    }

    printf("Array before sorting : ");
    printArray(arr,count);

    //Sort
    mergeSort(arr, count - 1);

    printf("Array after sorting : ");
    printArray(arr,count);

    return 0;
}

void printArray(int arr[], int count)
{
    int i = 0;
    for(i=0; i<count ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void mergeSort(int arr[], int high)
{
    int i = 0, j =0, k = 0, temp = 0;
    int* tempPtr = NULL;

    if(high == 0)
        return;

    mergeSort(arr, high / 2);
    mergeSort(arr + (high / 2) + 1, high - (high / 2) - 1);

    i = 0;
    j = (high / 2) + 1;

    tempPtr = (int*)malloc( (high+1) * sizeof(int));

    while( (i <= (high/2)) && (j <= high)){

        if(arr[i] < arr[j]){
            tempPtr[k++] = arr[i];
            i++;
        }
        else if( arr[i] > arr[j]){
            tempPtr[k++] = arr[j];
            j++;
        }
        else{
            tempPtr[k++] = arr[i];
            i++;
            j++;
        }
    }

    if( i <= (high/2)){
        while(i <= (high/2)){
            tempPtr[k++] = arr[i];
            i++;
        }
    }

    if( j <= high){
        while(j <= high){
            tempPtr[k++] = arr[j];
            j++;
        }
    }

    //Copy the temp array into arr
    i =0 ;
    while(i < k){
        arr[i] = tempPtr[i];
        i++;
    }

    free(tempPtr);

}






