#include<iostream>
#include<climits>
struct Node{
    int data;
    Node* next;
};
void enqueue(struct Node* &f,struct Node* &r,int val){
    struct Node* ptr=new Node;
    if(ptr!=NULL){
        ptr->data=val;
        ptr->next=NULL;
        std::cout<<"Added "<<val<<" to queue\n";
        if(f==NULL&&r==NULL){
            f=r=ptr;
        }
        else{
            r->next=ptr;
            r=ptr;
        }
    }
    else{
        std::cout<<"Queue overflow!\n";
    }
}
int dequeue(struct Node* &f){
    if(f!=NULL){
        struct Node* ptr=f;
        f=f->next;
        int data=ptr->data;
        std::cout<<"Dequeued "<<ptr->data<<"\n";
        delete ptr;
        return data;
    }
    std::cout<<"Queue Empty!\n";
    return INT_MIN;
}
void traversal(Node* ptr ){
        std::cout<<"printing\n";
        while(ptr!=NULL){
        std::cout<<ptr->data<<"\n";
        ptr=ptr->next;
        }
    }
int main(){
    struct Node* f=NULL;
    struct Node* r=NULL;
    dequeue(f);
    traversal(f);
    enqueue(f,r,10);
    traversal(f);
    enqueue(f,r,15);
    enqueue(f,r,17);
    enqueue(f,r,165);
    traversal(f);
    dequeue(f);
    traversal(f);
    return 0;
}