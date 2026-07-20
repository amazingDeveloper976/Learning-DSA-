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
    }
    else{
        std::cout<<"Queue overflow!\n";
    }
}
int dequeue(struct queue* q1){
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
    
    //BFS
    int visited[7]={0,0,0,0,0,0,0};
    int graph[7][7]={
    //  0 1 2 3 4 5 6
  /*0*/{0,1,1,1,0,0,0},
  /*1*/{1,0,1,0,0,0,0},
  /*2*/{1,0,0,1,1,0,0},
  /*3*/{0,1,1,0,1,0,0},
  /*4*/{0,0,1,1,0,1,1},
  /*5*/{0,0,0,0,1,0,1},
  /*6*/{0,0,0,0,1,1,0},
      };
    int u,i=1;
    visited[i]=1;
    enqueue(q1,i);
    while(!isEmpty(q1)){
        u=dequeue(q1);
        std::cout<<u;
        for(int j=0;j<7;j++){
            if(graph[u][j]==1 && visited[j]==0){
                visited[j]=1;
                enqueue(q1,j);
            }
        }
    }
    return 0;
}