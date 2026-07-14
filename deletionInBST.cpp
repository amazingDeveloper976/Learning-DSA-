#include<iostream>
#include<memory>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
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
struct Node* createNode(int data){
    struct Node* n=new Node;
    n->data=data;
    n->left=nullptr;
    n->right=nullptr;
    return n;
}

void deleteAll(struct Node* root){
    if(root!=nullptr){
        deleteAll(root->left);
        deleteAll(root->right);
        delete root;
    }
}

struct Node* inOrderPre(struct Node* root){
    root=root->left;
    while(root->right!=nullptr){
        root=root->right;
    }
    return root;
}

struct Node* deleteNode(struct Node* root,int val){
    if(root==nullptr){
        return nullptr;
    }
    if(root->left==nullptr&&root->right==nullptr&&root->data==val){
        delete root;
        return nullptr;  //no need for specifying nullptr as the deleteNide functiin called next will assign nullptr itself as this return statement
    }
    if(root->data>val){
        root->left=deleteNode(root->left,val);
    }
    else if(root->data<val){
        root->right=deleteNode(root->right,val);
    }
    else{
        //root->data=(inOrderPre(root))->data;
        struct Node* iPre=inOrderPre(root);
        root->data=iPre->data;
        root->left=deleteNode(root->left,iPre->data);
    }
    return root;
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
    search(root,8);
    deleteNode(root,8);
    search(root,8);
    deleteAll(root);
    std::cout<<"All nodes deleted\n";
    return 0;
}