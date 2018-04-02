/*****************************************************
 *Quick sort implementation in C program
 * **************************************************/
#include<stdio.h>
#include<stdlib.h>

//void quickSort(int arr[],int low, int high);
void quickSort(int arr[], int high);
int partition(int arr[], int high);
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
    quickSort(arr, count - 1);

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

void quickSort(int arr[], int high)
{
    int index = 0 ;

    if(high <= 0)
        return;

    index = partition(arr, high);
    quickSort(arr, index - 1);
    quickSort(arr + index + 1, high - index - 1);

}


int partition(int arr[], int pivot)
{
    int i = 0, temp = 0;
    int high = pivot;

    for(i=0 ; i < high; i++){

        if( ((arr[i] < arr[pivot]) && (i > pivot)) ||
            ((arr[i] > arr[pivot]) && (i < pivot))
          )
        {
           //Swap arr[i] and arr[pivot]
           temp = arr[i];
           arr[i] = arr[pivot];
           arr[pivot] = temp;
           //Swap ends
           pivot = i; 
        }
    }

    return pivot;
}




