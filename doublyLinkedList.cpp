#include<iostream>
class Node{
        public:
        int data;
        Node* nxt;
    Node* prev;
    };
void aheadBack(Node* &first){
    Node* ptr=first;
    std::cout<<"Going forward in list\n";
    while(ptr->nxt!=NULL){ //stopping ptr from being NULL
        std::cout<<ptr->data<<"\n";
        ptr=ptr->nxt;
    }
    std::cout<<ptr->data<<"\n";
    std::cout<<"Going backward in list\n";
    while(ptr!=NULL){
        std::cout<<ptr->data<<"\n";
        ptr=ptr->prev;
    }
}
Node* insertAtFirst(Node* &first,int data){
        std::cout<<"\nAdded "<<data<<" in first\n";
        Node* ptr;
        ptr=new Node;
        ptr->data=data;
        ptr->nxt=first;
        first->prev=ptr;
        ptr->prev=NULL;
        return ptr;
}
void insertAtIdx(Node* first,int idx,int data){
        std::cout<<"\nAdded "<<data<<" in given index\n";
        Node* ptr;
        ptr=new Node;
        Node* ptr2=first;
        ptr->data=data;
        for(int i=0;i<idx-1;i++){
                ptr2=ptr2->nxt;
        }
        ptr->nxt=ptr2->nxt;
        ptr2->nxt->prev=ptr;
        ptr2->nxt=ptr;
        ptr->prev=ptr2;
        
}
void insertAtEnd(Node* &first,int data){
        std::cout<<"\nAdded "<<data<<" in End\n";
        Node* ptr;
        ptr=new Node;
        Node* ptr2=first;
        ptr->data=data;
        while(ptr2->nxt!=NULL){
                ptr2=ptr2->nxt;
        }
        ptr2->nxt=ptr;
        ptr->nxt=NULL;
        ptr->prev=ptr2;
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
    first->nxt=second;
    first->prev=NULL;
    
    second->data=2;
    second->nxt=third;
    second->prev=first;
    
    third->data=3;
    third->nxt=fourth;
    third->prev=second;
    
    fourth->data=4;
    fourth->nxt=NULL;
    fourth->prev=third;
    
    aheadBack(first);
    //first=insertAtFirst(first,99);
    //insertAtIdx(first,2,199);
    insertAtEnd(first,299);    
    aheadBack(first);    
    return 0;
}