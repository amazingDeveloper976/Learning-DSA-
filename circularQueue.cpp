#include<iostream>
struct circQueue{
    int f,r,size;
    int* arr;
};
bool isFull(struct circQueue* &q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    return 0;
}
bool isEmpty(struct circQueue* &q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}
void enqueue(struct circQueue* &q,int val){
    if(!isFull(q)){
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        std::cout<<"Queued "<<val<<" \n";
    }
    else{
        std::cout<<"Queue overflow!\n";
    }
}
int deque(struct circQueue* &q){
    if(!isEmpty(q)){
        q->f=(q->f+1)%q->size;
        return q->arr[q->f];
    }
    std::cout<<"Queue underflow\n";
    return INT_MIN;
}
int main(){
    struct circQueue* q=new circQueue;
    q->size=3;  //can enter 1 less then size as one slot is reserved here for q->f's value
    q->f=q->r=0;
    q->arr=new int[q->size];
    enqueue(q,1);
    enqueue(q,3);
    std::cout<<"Dequeued "<<deque(q)<<"\n";
    std::cout<<"Dequeued "<<deque(q)<<"\n";
    std::cout<<"Dequeued "<<deque(q)<<"\n";
    delete[] (q->arr);
    delete q;
    return 0;
}