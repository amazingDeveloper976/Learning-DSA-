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
void preorder(struct Node* root){
    if(root!=nullptr){
        std::cout<<"Data is "<<root->data<<"\n";
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    struct Node* root=createNode(1);
    struct Node* n1=createNode(2);
    struct Node* n2=createNode(3);
    struct Node* n3=createNode(4);
    std::unique_ptr<struct Node> n4=std::make_unique<struct Node>();
    n4->data=5;n4->left=n4->right=nullptr;
    root->left=n1;
    root->right=n2;
    n1->left=n3;
    n1->right=n4.get();
    preorder(root);
    delete n3;
    delete n2;
    delete n1;
    delete root;
    return 0;
}