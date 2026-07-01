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
char stackTop(struct stack* &s1){
    if(s1->top!=-1){
    return (s1->arr[s1->top]);
    }
    return 0;
}
void push(struct stack* &s1,char val){
    if(isFull(s1)){
        std::cout<<"cannot push "<<val<<" to stack\n";
    }
    else{
    s1->top++;
    s1->arr[s1->top]=val;
    }
}
char pop(struct stack* &s1){
    if(isEmpty(s1)){
        std::cout<<"stack underflow: cannot pop from stack\n";
        return 0;
    }
    else{
    s1->top--;
    return s1->arr[s1->top+1];
    }
}
int precedence(char c){
    if(c=='+'||c=='-'){
        return 11;
    }
    else if(c=='*'||c=='/'){
        return 12;
    }
    return 0;
}
int isOperator(char c){
    if (c=='+'||c=='-'||c=='*'||c=='/'){
        return 1;
    }
    return 0;
}
std::string infixToPostfix(std::string infix){
    struct stack* s1=new stack;
    s1->top=-1;
    s1->size=infix.length();
    s1->arr=new char[s1->size];
    std::string postfix="";
    int i=0; //to track infix
    for(i=0;i<infix.size();i++){
        if(!isOperator(infix[i])){
            postfix+=infix[i];
        }
        else{
            if(precedence(infix[i])>precedence(stackTop(s1))){
                push(s1,infix[i]);
            }
            else{
                while(precedence(infix[i])<=precedence(stackTop(s1))){
                postfix+=pop(s1);
                }
           push(s1,infix[i]);
        }
    }
    }
    while(!isEmpty(s1)){
        postfix+=pop(s1);
    }
    delete[] (s1->arr);
    delete s1;
    return postfix;
}
int main(){
    std::string infix=" x-y+z";
    std::cout<<infixToPostfix(infix);
    return 0;
}