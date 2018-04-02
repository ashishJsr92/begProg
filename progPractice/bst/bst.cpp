#include<iostream>
using namespace std;

typedef struct node
{
    int info;
    struct node* left;
    struct node* right;
}Node;


class Bst
{
    Node* root;

    public:
        Bst();
        void insertRecurrsive(Node*, int);
        void insert(int value);
        void remove(int info);
        void print(int);
        void printInorder(Node*);
};

Bst::Bst()
{
    root = NULL;
}

void Bst::insertRecurrsive(Node* ptr, int value)
{
    if(ptr == NULL){
        ptr = root;
    }

    if(ptr->info == value)
    {
        return;
    }
    else if(ptr->info > value){
        if(ptr->left == NULL){
            Node* temp = new Node;
            temp->info = value;
            temp->right = temp->left = NULL;
            ptr->left = temp;
        } 
        else{
            insertRecurrsive(ptr->left, value);
        }
    }
    else{
        if(ptr->right == NULL){
            Node* temp = new Node;
            temp->info = value;
            temp->right = temp->left = NULL;
            ptr->right = temp;
        } 
        else{
            insertRecurrsive(ptr->right, value);
        }
    }
}

void Bst::insert(int value)
{
    Node* temp = root;

    Node* node = new Node;

    node->info = value;
    node->left = node->right = NULL;
 
    if(root == NULL){
        root = node;
    }
    else{
        while(temp != NULL)
        {
            if(temp->info == node->info){
                return;
            }
            else if(temp->info < node->info)
            {
                if(temp->right == NULL){
                    temp->right = node;
                    break;
                }
                else{
                    temp = temp->right;
                }
            }
            else{
                if(temp->left == NULL){
                    temp->left = node;
                    break;
                }
                else{
                    temp = temp->left;
                }
            }
        }
    }
}

void Bst::print(int order)
{
    if(order == 1){
        printInorder(root);
    }

}


void Bst::printInorder(Node* node)
{
    if(node->left != NULL){
        printInorder(node->left);
    }

    cout<< node->info << "  ";

    if(node->right != NULL){
        printInorder(node->right);
    }
}


void Bst::remove(int info)
{
    Node* ptr = root;
    Node* temp = NULL, *parent = NULL, *newNode = NULL;
    int ind = 0;

    while(ptr != NULL)
    {
        if(ptr->info == info)
        {
            break;
        }
        else if(ptr->info < info){
            parent = ptr;
            ind = 2;
            ptr = ptr->right;
        }
        else{
            parent = ptr;
            ind = 1;
            ptr = ptr->left;
        }
    }

    if(ptr == NULL){
        cout << "Element not found" << endl;
        return;
    } 

    if( ptr->right == NULL)
    {
       newNode = ptr->left;
    }
    else if( ptr->left == NULL)
    {
       newNode = ptr->right;
    }
    else if( (ptr->left == NULL) && (ptr->right == NULL)){
        newNode = NULL;
    }
    else{
        newNode = ptr->right;

        temp = ptr->right;
        while(temp->left != NULL)
            temp = temp->left;

        temp->left = ptr->left;

        ptr->left = ptr->right = NULL;
    }

    if(parent == NULL){
        root = newNode;
    }
    else{

        if(ind == 1){
            parent->left = newNode;
        }
        else{
            parent->right = newNode;
        }
    }
    
    delete ptr;
}

int main()
{
    Bst tree; 

    tree.insert(100);
    tree.insertRecurrsive(NULL,90);
    tree.insert(90);
    tree.insert(10);
    tree.insert(110);
    tree.insertRecurrsive(NULL,0);
    tree.insertRecurrsive(NULL,200);
    tree.insert(200);

    tree.print(1);
    cout << endl;

    tree.remove(100);
    tree.remove(300);
    tree.remove(90);
    tree.remove(0);
    tree.print(1);
    cout << endl;

    return 0;
}


