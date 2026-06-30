#include<iostream>
#include<climits>
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
void peek(struct Node* &top,int pos){
    struct Node* ptr=top;
    for(int i=0;(i<pos-1&&ptr!=NULL);i++){
        ptr=ptr->next;
    }
    if(ptr!=NULL){
        std::cout<<"Value at position "<<pos<<" is "<<ptr->data<<"\n";
    }
    else{
    std::cout<<"Value at position "<<pos<<" is "<<INT_MIN<<"\n";
}}
void stackTop(struct Node* &top){
    peek(top,1);
}
int main(){
    struct Node* top=new Node;
    top->data=99;
    top->next=NULL;
    push(top,1);
    push(top,3);
    peek(top,3);
    stackTop(top);
    
    return 0;
}