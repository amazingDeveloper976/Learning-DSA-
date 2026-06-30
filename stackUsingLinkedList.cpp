#include<iostream>
struct Node{
    int data;
    Node* next;
};
int isEmpty(struct Node* &top){
    if(top==NULL){
        return 1;
    }
    return 0;
}
int isFull(){
    struct Node* n=new Node;
    if(n==NULL){
        return 1;
    }
    delete n;
    return 0;
}
void push(struct Node* &top,int val){
    if(isFull()==0){
        struct Node* n=new Node;
        n->data=val;
        n->next=top;
        top=n;
        std::cout<<"Added "<<val<<"\n";
    }
    else{
    std::cout<<"Stack Overflow!!\n";
    }
}
int pop(struct Node* &top){
    if(isEmpty(top)==0){
        struct Node* n=top;
        top=top->next;
        int data=n->data;
        delete n;
        std::cout<<"Removed "<<data<<"\n";
        return data;
    }
    std::cout<<"Stack Underflow!\n";
    return INT_MIN;
}
void traversal(struct Node* ptr){
        while(ptr!=NULL){
        std::cout<<ptr->data<<"\n";
        ptr=ptr->next;
        }
}

int main(){
    struct Node* top=new Node;
    top->data=99;
    top->next=NULL;
    pop(top);
    pop(top);
    push(top,5);
    pop(top);
    traversal(top);
    
    return 0;
}