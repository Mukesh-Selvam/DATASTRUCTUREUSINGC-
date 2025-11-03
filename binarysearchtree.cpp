#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int data){
    Node* temp=new Node;
    temp->left=NULL;
    temp->right=NULL;
    temp->data=data;
    return temp;
}
void insertNode(Node** root,int data){
    Node* nd=newNode(data);
    if(*root==NULL){
        (*root)=nd;
        return;
    }else{
        Node*temp=*root;
        while(1){
            if(data>temp->data && temp->right!=NULL){
                temp=temp->right;
            }else if(data>temp->data){
                temp->right=nd;
                break;
            }else if(data<temp->data && temp->left !=NULL){
                temp=temp->left;
            }else if(data<temp->data){
                temp->left=nd;
                break;
            }
        }
    }
}
struct QueueNode{
    Node* head;
};
struct Queue{
    QueueNode* a;
    int size;
    int front;
    int rear;
};
Queue* createQueue(int n){
    Queue* q=new Queue;
    q->a=new QueueNode[n];
    q->size=n;
    q->front=q->rear=0;
    return q;
}
void enqueue(Queue* q,Node* temp){
    if(q->rear==q->size){
        cout<<"Queue Full";
    }else{
        q->a[q->rear].head=temp;
        q->rear++;
    }
}
Node* dequeue(Queue* q){
    if(q->rear==q->front){
        return NULL;
    }else{
        return q->a[q->front++].head;
    }
}
int isEmpty(Queue* q){
    if(q->front==q->rear) return 1;
    return 0;
}
void inorder(Node* root){           //inorder traversal
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void preorder(Node* root){       //preorder traversal
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root){      //postorder traversal
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

void levelorder(Node* root,int size){  //levelorder traversal
    Queue* q=createQueue(size);
    enqueue(q,root);
    while(!isEmpty(q)){
        Node*temp=dequeue(q);
        if(temp->left!=NULL){
            enqueue(q,temp->left);
        }
        if(temp->right!=NULL){
            enqueue(q,temp->right);
        }
            cout<<temp->data<<" ";
    }
}
int main(){
    Node* root=NULL;
    insertNode(&root,89);
    insertNode(&root,12);
    insertNode(&root,56);
    insertNode(&root,34);
    insertNode(&root,80);
    insertNode(&root,100);
    insertNode(&root,120);
    insertNode(&root,93);
    cout<<"Inorder traversal    : ";
    inorder(root);
    cout<<"\nPreorder traversal   : ";
    preorder(root);
    cout<<"\nPostorder traversal  : ";
    postorder(root);
    cout<<"\nLevelorder traversal : ";
    levelorder(root,8);
}