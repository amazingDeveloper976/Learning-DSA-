#include<iostream>
/*i know that i could have used:
#include<list>
I could but for understanding what really happens under the hood, this was must.
*/
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
//Case: 1
Node* insertAtFirst(Node* first,int data){
    Node* ptr=new Node;
    ptr->nxt=first;
    ptr->data=data;
    return ptr;
}
//Case: 2
Node* insertInIdx(Node* first,int data,int idx){
    Node* ptr=new Node;
    Node* fst=first;
    int i=0;
    while(i!=idx-1){ //idx-1 because i want to change the nxt of prev element
    fst=fst->nxt;
        i++;
    }
    ptr->nxt=fst->nxt;
    ptr->data=data;
    fst->nxt=ptr;
    return ptr;
}
//Case: 3
void insertAtEnd(Node* first,int data){
    Node* ptr=new Node;
    ptr->nxt=NULL;
    ptr->data=data;
    Node* fst=first;
    while(fst->nxt!=NULL){
        fst=fst->nxt;
    }
    fst->nxt=ptr;
}
//Case: 4
void insertAfterNode(Node* prevNode,int data){
    Node* ptr=new Node;
    ptr->data=data;
    ptr->nxt=prevNode->nxt;
    prevNode->nxt=ptr;
}

int main(){
    Node* first;  
    Node* second;
    Node* third;
    first=new Node; 
    second=new Node;
    third=new Node;
    
    first->data=1; 
    (*first).nxt=second;
    
    second->data=5;
    second->nxt=third;
    
    third->data=7;
    third->nxt=NULL;
    
    traversal(first);
    //first=insertAtFirst(first,99); 
    //insertInIdx(first,98,1);
    //insertAtEnd(first,97);
    insertAfterNode(second,96);
    traversal(first);
    return 0;
}