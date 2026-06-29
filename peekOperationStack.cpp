#include<iostream>
    struct stack{
        int size;
        int top;
        int* arr;
    };
    bool isEmpty(struct stack* &ptr){
        if(ptr->top==-1){
            std::cout<<"Stack is Empty!\n";
            return 1;
        }
        return 0;
    }
    bool isFull(struct stack* &ptr){
        if(ptr->top==ptr->size-1){
            std::cout<<"Stack is Full!\n";
            return 1;
        }
        return 0;
    }
void push(struct stack* &ptr,int val){
    if(isFull(ptr)){
        std::cout<<"cannot push "<<val<<" to stack\n";
    }
    else{
    ptr->top++;
    ptr->arr[ptr->top]=val;
    }
}
int pop(struct stack* &ptr){
    if(isEmpty(ptr)){
        std::cout<<"stack underflow: cannot pop from stack\n";
        return INT_MIN;
    }
    else{
    ptr->top--;
    return ptr->arr[ptr->top+1];
    }
}
void run(struct stack* &ptr,int size){
    for(int i=0;i<size;i++){
        int val;
        std::cout<<"Add for index #"<<i<<" ";
        std::cin>>val;
        push(ptr,val);
    }
}
int peek(struct stack* &ptr,int i){
    int arrIdx=ptr->top-i+1;
    if(arrIdx<0){
        std::cout<<"Invalid operation!\n";
        return INT_MIN;
    }
    return ptr->arr[arrIdx];
}
int main(){
    struct stack* s1=new struct stack;
    s1->top=-1;
    s1->size=4;
    s1->arr=new int[s1->size];
    run(s1,4);
    for(int i=1;i<=s1->top+1;i++){
    std::cout<<"value at position "<<i<<" is "<<peek(s1,i)<<"\n";
    }
return 0;
}
