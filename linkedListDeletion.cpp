#include<iostream>
class Node{
    public:
    int data;
    Node* nxt;
};
void traversal(Node* ptr ){
        while(ptr!=NULL){
        std::cout<<ptr->data<<"\n";
        ptr=ptr->nxt;
        }
    std::cout<<"\n";
    }
Node* delFirst(Node* first){
    Node* ptr=first;
    first=first->nxt;
    delete(ptr);
    return first;
}
void delIdx(Node* &first,int idx){
    Node* ptr=first;
    int i=0;
    if (idx==0){
        first=delFirst(first);
    }
    else{
    while(i<idx-1){
        ptr=ptr->nxt;
        i++;
    }
    Node* ptr2=ptr->nxt;
    ptr->nxt=ptr->nxt->nxt;
    delete ptr2;
}}
void delLast(Node* first){
    Node* ptr=first;
    while(ptr->nxt->nxt!=NULL){
        ptr=ptr->nxt;
    }
    delete(ptr->nxt);
    ptr->nxt=NULL;
}

void delNodeWithGivenValue(Node* first,int value){
    Node* ptr=first;
    while(ptr->nxt->data!=value){
        ptr=ptr->nxt;
    }
    Node* ptr2=ptr->nxt;
    ptr->nxt=ptr->nxt->nxt;
}

int main(){
    Node* first;  
    Node* second;
    Node* third;
    Node* fourth;
    first=new Node; 
    second=new Node;
    third=new Node;
    fourth=new Node;
    
    first->data=1; 
    (*first).nxt=second;
    
    second->data=5;
    second->nxt=third;
    
    third->data=7;
    third->nxt=fourth;
    
    fourth->data=9;
    fourth->nxt=NULL;
    
    traversal(first);
    
    //first=delFirst(first);
    delIdx(first,0);
    //delLast(first);
    //delNodeWithGivenValue(first,7);
    traversal(first);
   
    return 0;
}