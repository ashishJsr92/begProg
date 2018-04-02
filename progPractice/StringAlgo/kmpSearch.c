/********************************************
 * Program : Implement KMP String search Algo
 *
 * *****************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int* createKMPTable(char* pattern);
int  kmpSearch(char* text, char* pattern, int* kmpTable);

int main()
{
    char text[300] = {'\0'};
    char pattern[50] = {'\0'};
    int* kmpTable = NULL, index = 0;

    //Take input text
    printf("Enter the text : ");
    scanf("%[^\n]",text);

    getchar();
    //Take input pattern
    printf("Enter the pattern : ");
    scanf("%[^\n]",pattern);

    kmpTable = createKMPTable(pattern);
    
    //if(kmpTable)
      //  index = kmpSearch(text, pattern, kmpTable); 

    while(index < strlen(pattern)){
        printf("%d ",kmpTable[index]); 
        index++;
    }
    printf("\n");


    return 0;
}

int* createKMPTable(char* pattern)
{
    int length = 0 , i = 1,j = 0, *kmpTable = NULL;
    if(!pattern)
        return NULL;

    length = strlen(pattern);

    if(length)
        kmpTable = (int*)calloc(length, sizeof(int));
    else
        return NULL;

    kmpTable[0] = 0;
    while(pattern[i] != '\0'){
        if(pattern[i] == pattern[j]){
            kmpTable[i] = j+1;
            i++;
            j++;
        }
        else{
            if(j ==0){
                kmpTable[i] = 0;
                i++;
            }
            else{
                j = kmpTable[j - 1];
            }
        }
    }
   
    return kmpTable; 
}
