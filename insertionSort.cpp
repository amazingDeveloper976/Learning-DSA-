#include<iostream>
void printArr(int* arr,int n){
    for(int i=0;i<n;i++){
        std::cout<<"Index "<<i<<" is"<<arr[i]<<"\n";
    }
    std::cout<<"\n\n";
}
void insertionSort(int* arr,int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&& arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int arr[]={9,4,1,6,8,0};
    int n=sizeof(arr)/sizeof(int);
    printArr(arr,n);
    insertionSort(arr,n);
    printArr(arr,n);
    return 0;
}