#include<iostream>
//#include<print> tried didn't run
class Node{
        public:
        int data;
        Node* nxt;
    };
void traversal(Node* &first){
    Node* ptr=first;
    do{
        std::cout<<ptr->data<<"\n";
        ptr=ptr->nxt;
    }while(ptr!=first);
    std::cout<<"\n";
}
Node* insertAtFirst(Node* first,int data){
    Node* ptr=new Node;
    Node* ptr2=first->nxt;
    ptr->nxt=first;
    ptr->data=data;
    while(ptr2->nxt!=first){
        ptr2=ptr2->nxt;
    }
    ptr2->nxt=ptr;
    return ptr;
}
int main(){
    //std::print("Done");
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
    
    second->data=2;
    second->nxt=third;
    
    third->data=3;
    third->nxt=fourth;
    
    fourth->data=4;
    fourth->nxt=first;
    
    traversal(first);
    first=insertAtFirst(first,0);
    first=insertAtFirst(first,99);
    traversal(first);
    return 0;
}