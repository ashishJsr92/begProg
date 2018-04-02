#include<iostream>
using namespace std;


typedef struct node
{
    int info;
    struct node* left;
    struct node* right;
}Tree;


Tree* preorderToBst(int *values, int limit);
void  preorder(Tree*);

int main()
{
    int values1[] = {10, 5, 1, 7, 40, 50};
    int values2[] = {10, 5, 4, 3, 2, 1};
    int values3[] = {10, 11, 12, 70, 40, 50};

    Tree* root1 = preorderToBst(values1,6);
    Tree* root2 = preorderToBst(values2,6);
    Tree* root3 = preorderToBst(values3,6);

    preorder(root1);
    cout<< endl << endl;
    preorder(root2);
    cout<< endl << endl;
    preorder(root3);
    cout<< endl << endl;

    return 0;
}

Tree* preorderToBst(int *values, int limit)
{
    if(limit <= 0)
        return NULL;

    int i = 0;
    Tree* root = new Tree;
    root->info = values[0];

    for(i=1 ; i<limit; i++){
        if(values[i] > values[0])
            break; 
    }

    if( i == limit){
        root->right = NULL;
        root->left = preorderToBst(values + 1,limit-1);
    }
    else if(i < limit){

        if(i == 1){
            root->left = NULL;
        }
        else{
            root->left = preorderToBst(values+1, i-1);
        }
        root->right = preorderToBst(values + i, limit - i);
    }

    return root;
}

void preorder(Tree* root)
{
    if(root == NULL)
        return;

    cout << root->info << " ";
    preorder(root->left);
    preorder(root->right);
}
