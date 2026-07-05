#include<iostream>
void printArr(int* arr,int n){
    for(int i=0;i<n;i++){
        std::cout<<"Index "<<i<<" is"<<arr[i]<<"\n";
    }
    std::cout<<"\n\n";
}
void selectionSort(int* arr,int n){
    int idxOfMin;
    for(int i=0;i<n-1;i++){
        idxOfMin=i;
        std::cout<<"Pass "<<i+1<<"\n";
        for(int j=i+1;j<n;j++){
            if(arr[idxOfMin]>arr[j]){
                idxOfMin=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[idxOfMin];
        arr[idxOfMin]=temp;
    }
}
int main(){
    int arr[]={9,4,1,6,8,0};
    //int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    printArr(arr,n);
    selectionSort(arr,n);
    printArr(arr,n);
    return 0;
}