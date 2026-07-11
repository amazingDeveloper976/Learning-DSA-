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
        std::cout<<"Data is "<<root->data<<"\n";
        inOrder(root->right);
    }
}
int isBST(struct Node* root){
    static struct Node* prev=nullptr;
    if(root!=nullptr){
        if(!isBST(root->left)){ //if not BST then it bubbles up and eventually 0
            return 0;
        }
        if(prev!=nullptr&&root->data<=prev->data){ //if nullptr then we are at leaf node so nothing is there to compare and we are moving by inorder traversal way
            return 0;                              //so if we are at left of a node, the node's data is greater then its left and smaller then its right, being true for BST 
                                                    //hence this condition will be false for BST. This line will work even for node's right in return
        }                                     //return 0 and same as above if statement, it bubbles up
        
        
            prev=root;               //we finished all these so the previous node we worked on is current
        return isBST(root->right);   //also checking right node, if false, same as above it bubbles up
    }
    return 1;
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
    inOrder(root);
    std::cout<<isBST(root);
    delete n4;
    delete n3;
    delete n2;
    delete n1;
    delete root;
    return 0;
}