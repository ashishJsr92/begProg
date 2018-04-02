/********************************************
 *Program : Breadth First Traversal
 * *****************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node * left;
    struct node * right;
}Node;

typedef struct qnode
{
    Node* ptr;
    struct qnode* next;
}qNode;


Node*  insert(Node* root,int value);
void   print(Node* root);
qNode* enqueue(qNode* front, Node* val);
qNode* dequeue(qNode* front, Node** val);
void bfs(Node* root, qNode* front);

int main()
{
    int num = 0, val = 0;
    Node* root = NULL;
    qNode* front = NULL;

    printf("Enter the number of Elements : ");
    scanf("%d",&num);

    while(num > 0){

        printf("Number : ");
        scanf("%d",&val);
        root = insert(root, val);
        num--;
    }

    bfs(root, front );
    return 0;
}

void bfs(Node* root, qNode* front)
{
    Node* ptr = NULL;

    if(root != NULL){

        printf("%d\n" ,root->info);
        if(root->left)
            front = enqueue(front, root->left);

        if(root->right)
            front = enqueue(front, root->right);
    }
    else{

        if(front == NULL)
            return;

        front = dequeue(front, &ptr);
        printf("%d\n",ptr->info);
        if(ptr->left)
            front = enqueue(front, ptr->left);

        if(ptr->right)
            front = enqueue(front, ptr->right);
    }

    bfs(NULL, front);
}

qNode* enqueue(qNode* front, Node* val)
{
    qNode* temp = front;
    qNode* value = (qNode*)malloc(sizeof(qNode));

    value->ptr = val;
    value->next = NULL;

    if(front == NULL)
        front = value;
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = value;
    }

    return front;
}

qNode* dequeue(qNode* front, Node** val)
{
    qNode* temp = NULL;

    if(front == NULL)
        return NULL;

    *val = front->ptr;
    temp = front;
    front = front->next;
    temp->next = NULL;
    free(temp);
    return front;
}

Node* insert(Node* root,int value)
{
    Node* temp = root;

    Node* node = (Node*)malloc(sizeof(Node));

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

    return root;
}



