#include<iostream>
void printArr(int* arr,int n){
    for(int i=0;i<n;i++){
        std::cout<<"Index "<<i<<" is"<<arr[i]<<"\n";
    }
    std::cout<<"\n\n";
}
void countSort(int* arr,int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    max++;//if i dont do max++ then if max is 3,i wont get 3th index on count 
    int count[max];
    for(int i=0;i<max;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[arr[i]]=count[arr[i]]+1;
    }
    int j=0;
    for(int i=0;i<max;i++){
        while(count[i]!=0){
            arr[j]=i;
            j++;
            count[i]--;
        }
    }
}
int main(){
    int arr[]={1,3,5,6,1,8,9};
    int n=sizeof(arr)/sizeof(int);
    printArr(arr,n);
    countSort(arr,n);
    printArr(arr,n);
    return 0;
}