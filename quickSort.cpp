#include<iostream>
void printArr(int* arr,int n){
    for(int i=0;i<n;i++){
        std::cout<<"Index "<<i<<" is"<<arr[i]<<"\n";
    }
    std::cout<<"\n\n";
}
int partition(int* arr,int low,int high){
    int pivot=arr[low];
    int i=low+1;int j=high;
    do{
    while(arr[i]<=pivot&&i<=high){
        i++;
    }
    while(arr[j]>pivot&&j>=low){
        j--;
    }
    if(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    }while(i<j);
       int temp=arr[low];
        arr[low]=arr[j];
        arr[j]=temp;
    return j;
}
void quickSort(int* arr,int low,int high){
    int partitionIndex;
    if(low<high){
    partitionIndex=partition(arr,low,high);
    quickSort(arr,low,partitionIndex-1);
    quickSort(arr,partitionIndex+1,high);
    }
}
int main(){
    int arr[]={9,4,1,6,4,8,0,4,4};
    int n=sizeof(arr)/sizeof(int);
    printArr(arr,n);
    quickSort(arr,0,n-1);
    printArr(arr,n);
    return 0;
}