#include<iostream>
struct Node{
    int data;
    int height;
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
int getHeight(struct Node* n){
    if(n==nullptr){
        return 0;
    }
    return n->height;
}
struct Node* createNode(int data){
    struct Node* n=new Node;
    n->data=data;
    n->left=nullptr;
    n->right=nullptr;
    n->height=1;
    return n;
}
int max(int n1,int n2){
    if(n1>n2){
        return n1;
    }
    else if(n2>n1){
        return n2;
    }
    else{
        return n1;
    }
}
int getBalanceFactor(struct Node* n){
    if(n==nullptr){
        return 0;
    }
    return getHeight(n->left)-getHeight(n->right);
}
struct Node* rightRotate(struct Node* n){
    struct Node* temp=n->left;
    struct Node* temp2=temp->right;
    
    temp->right=n;
    n->left=temp2;
    
    n->height=max(getHeight(n->left),getHeight(n->right))+1;
    temp->height=max(getHeight(temp->left),getHeight(temp->right))+1;
    
    return temp;
}
struct Node* leftRotate(struct Node* n){
    struct Node* temp=n->right;
    struct Node* temp2=temp->left;
    
    temp->left=n;
    n->right=temp2;
    
    n->height=max(getHeight(n->left),getHeight(n->right))+1;
    temp->height=max(getHeight(temp->left),getHeight(temp->right))+1;
    
    return temp;
}
struct Node* insert(struct Node* n,int val){
    if(n==nullptr){
        return createNode(val);
    }
    if(n!=nullptr){
        if(val < n->data){
            n->left=insert(n->left,val);
        }
        else if(val > n->data){
            n->right=insert(n->right,val);
        }
        else{return n;}
    }
    n->height=max(getHeight(n->left),getHeight(n->right))+1;
    int BF=getBalanceFactor(n);
    if(BF>1 && val < n->left->data){
        n=rightRotate(n); //or return rightRotate(n)
    }
    else if(BF<-1 && val > n->right->data){
        n=leftRotate(n);
    }
    else if(BF>1 && val > n->left->data){
        n->left=leftRotate(n->left);
        n=rightRotate(n);
    }
    else if(BF<-1 && val < n->right->data){
        n->right=rightRotate(n->right);
        n=leftRotate(n);
    }
    return n;
}
int main(){
    struct Node* root=createNode(50);
    root=insert(root,1);
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,5);
    search(root,50);
    return 0;
}