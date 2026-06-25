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
    return 0;
}