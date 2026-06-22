#include<iostream>
struct Node{
    int data;
    Node* nxt;
};
void traversal(Node* ptr ){
        while(ptr!=NULL){
        std::cout<<ptr->data;
        ptr=ptr->nxt;
        }
    }
int main(){
    Node* first; //created first as pointer(as instance) so, thr instance doesn't have name to call like Node1.data  
    Node* second;
    Node* third;
    first=new Node; //allocating heap memory[new gives memory address of a Node datatype in heap and first is a pointer so it stores the address]
    second=new Node;
    third=new Node;
    
    first->data=1; //dereferencing first so we could get access to its ojbects
    (*first).nxt=second;
    
    second->data=5;
    second->nxt=third;
    
    third->data=7;
    third->nxt=NULL;
    
    traversal(first);
    
    return 0;
}