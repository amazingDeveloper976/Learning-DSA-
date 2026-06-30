#include<iostream>
#include<string>
struct stack{
    int size;
    int top;
    char* arr;
};
int isFull(struct stack* &s1){
    if(s1->top==s1->size-1){
        return 1;
    }
    return 0;
}
int isEmpty(struct stack* &s1){
    if(s1->top==-1){
        return 1;
    }
    return 0;
}
void push(struct stack* &ptr,char val){
    if(isFull(ptr)){
        std::cout<<"cannot push "<<val<<" to stack\n";
    }
    else{
    ptr->top++;
    ptr->arr[ptr->top]=val;
    }
}
char pop(struct stack* &ptr){
    if(isEmpty(ptr)){
        std::cout<<"stack underflow: cannot pop from stack\n";
        return 0;
    }
    else{
    ptr->top--;
    return ptr->arr[ptr->top+1];
    }
}
int parenthesisMatching(std::string &expression){
    struct stack* s1=new stack;
    s1->size=expression.length();
    s1->top=-1;
    s1->arr=new char[s1->size]; //stack to hold parenthesis
    for(int i=0;expression[i]!='\0';i++){
        if(expression[i]=='('){
            push(s1,'(');
        }
        else if(expression[i]==')'){
            if(isEmpty(s1)){
                delete(s1->arr);
                delete s1;
                return 0;
            }
            pop(s1);
        }
    }
    if(isEmpty(s1)){
        delete (s1->arr);
        delete s1;
        return 1;
    }
    delete (s1->arr);
    delete s1;
    return 0;
}
int main(){
    std::string expression="A2*3((+4))()";
    if(parenthesisMatching(expression)){
        std::cout<<"Matched!\n";
    }
    else{
        std::cout<<"Not Matched!\n";
    }
    return 0;
}