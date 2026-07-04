#include<iostream>
struct DEqueue{
    int data;
    int f,r,size;
    int* arr;
};
void enqueueF(struct DEqueue* &q,int val){
    if(q->f+1!=q->r){
        q->f++;
        q->arr[q->f]=val;
        std::cout<<"Queued "<<val<<" at front\n";
    }
    else{
        std::cout<<"No space in front\n";
    }
}
void enqueueR(struct DEqueue* &q,int val){
    if(q->r-1!=q->f){
        q->r--;
        q->arr[q->r]=val;
        std::cout<<"Queued "<<val<<" at rear\n";
    }
    else{
        std::cout<<"No space in rear\n";
    }
}
int dequeueF(struct DEqueue* &q){
    if(q->f!=-1&&q-r!=q->size){
        q->f--;
        std::cout<<"Dequeued "<<q->arr[q->f+1]<< " from front\n";
        return q->arr[q->f+1];
    }
    std::cout<<"Oueue underflow!\n";
    return INT_MIN;
}
int dequeueR(struct DEqueue* &q){
    if(q->r!=q->size){
        q->r++;
        std::cout<<"Dequeued "<<q->arr[q->r-1]<< " from rear\n";
        return q->arr[q->r-1];
    }
    std::cout<<"Oueue underflow!\n";
    return INT_MIN;
}

// dequeue operation from one side fails when i add elements from a single side
//like [0,1,2] from front but dequeueR fails as q->r=q->size. same goes for if i added from only rear

int main(){
    struct DEqueue* q=new DEqueue;
    q->size=2;
    q->arr=new int[q->size];
    q->f=-1;
    q->r=q->size;
    dequeueR(q);
    enqueueR(q,5);
    enqueueR(q,8);
    dequeueR(q);
    dequeueR(q);
    enqueueR(q,8);
    enqueueF(q,9);
    delete[] (q->arr);
    delete q;
    return 0;
}