#include<iostream>
#include<climits>
struct queue{
    int f,size,r;
    int* arr;
};
bool isFull(struct queue* q1){
    if(q1->r==q1->size-1){
        return 1;
    }
    return 0;
}
bool isEmpty(struct queue* q1){
    if(q1->r==q1->f){
        return 1;
    }
    return 0;
}
void enqueue(struct queue* &q1,int val){
    if(!isFull(q1)){
        q1->r++;
        q1->arr[q1->r]=val;
        std::cout<<"Queued "<<val<<" \n";
    }
    else{
        std::cout<<"Queue overflow!\n";
    }
}
int deque(struct queue* q1){
    if(!isEmpty(q1)){
        q1->f++;
        return q1->arr[q1->f];
    }
    std::cout<<"Queue underflow\n";
    return INT_MIN;
}
int main(){
    struct queue* q1=new queue;
    q1->size=100;
    q1->f=q1->r=-1;
    q1->arr=new int[q1->size];
    enqueue(q1,1);
    enqueue(q1,3);
    std::cout<<"Dequeued "<<deque(q1)<<"\n";
    std::cout<<"Dequeued "<<deque(q1)<<"\n";
    std::cout<<"Dequeued "<<deque(q1)<<"\n";
    delete[] (q1->arr);
    delete q1;
    return 0;
}