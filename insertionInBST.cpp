#include<iostream>
#include<memory>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data){
    struct Node* n=new Node;
    n->data=data;
    n->left=nullptr;
    n->right=nullptr;
    return n;
}
void inOrder(struct Node* root){
    if(root!=nullptr){
    inOrder(root->left);
    std::cout<<root->data<<"\n";
    inOrder(root->right);
    }
    return;
}
struct Node* search(struct Node* n,int val){
    while(n!=nullptr){
        if(n->data==val){
            std::cout<<"Found\n";
            return n;
        }
        else if(val<n->data){
            n=n->left;
            std::cout<<"Left\n";
        }
        else{ n=n->right;std::cout<<"Right\n"; }
    }
    std::cout<<"Not found\n";
    return nullptr;
}
void insert(struct Node* root,int val){
    struct Node* n=new Node;
    n->data=val;
    n->left=n->right=nullptr;
    struct Node* prev;
    while(root!=nullptr){
        prev=root;
        if(root->data<val){
            root=root->right;
        }
        else if(root->data>val){
            root=root->left;
        }
        else{
            std::cout<<"Already in Tree\n";
            delete n;
            return;
        }
    }
    if(val<prev->data){
        prev->left=n;
    }
    if(val>prev->data){
        prev->right=n;
    }
    
}
void deleteAll(struct Node* root){
    if(root!=nullptr){
        deleteAll(root->left);
        deleteAll(root->right);
        delete root;
    }
    return;
}
int main(){
    struct Node* root=createNode(10);
    struct Node* n1=createNode(8);
    struct Node* n2=createNode(11);
    struct Node* n3=createNode(7);
    struct Node* n4=createNode(9);
    root->left=n1;
    root->right=n2;
    n1->left=n3;
    n1->right=n4;
    search(root,11);
    inOrder(root);
    insert(root,12);
    inOrder(root);
    search(root,11);
    deleteAll(root);
    std::cout<<"All nodes deleted\n";
    return 0;
}