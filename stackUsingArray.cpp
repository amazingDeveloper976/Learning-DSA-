#include<iostream>
class stack{
    public:
    int top; //for index of top element
    int size;
    int* arr;
    int isEmpty(class stack* &sPtr);
    int isFull(class stack* &sPtr);
};
int stack::isEmpty(class stack* &sPtr){
    if(sPtr->top==-1){
        return 1;
    }
    return 0; 
}
int stack::isFull(stack* &sPtr){
    if(sPtr->top==sPtr->size-1){
        return 1;
    }
    return 0;
}
int main(){
    class stack *s1=new stack;
    int a;
    std::cout<<"Enter size of array\n";
    std::cin>>a;
    s1->size=a;
    s1->top=-1; //-1 indicates no element
    s1->arr=new int[(*s1).size];
    for(int i=0;i<s1->size;i++){
        std::cout<<"Enter #"<<i+1<<" ";
        std::cin>>s1->arr[i];
        s1->top++;
    }
    if (s1->isFull(s1)){
        std::cout<<"Stack is full!\n";
    }
    else{
        std::cout<<"Stack is not full!\n";
    }
    return 0;
}