#include<iostream>
#include<algorithm>
int ls(int arr[],int size,int element){
        for(int i=0;i<size;i++){
            if(arr[i]==element){
                return i;
            }
        }
    return -1;
    }
int bs(int arr[],int size,int element){
    int low,mid,high;
    low=0;high=size-1;
        while (low<high){
            mid=(low+high)/2;
            if(arr[mid]==element){
                return mid;
            }
            if (arr[mid]<element){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
int main(){
    int arr[]={2,8,5,56,43,784,29};
    int element=56;
    int size=sizeof(arr)/sizeof(int);
    int index=ls(arr,size,element);
    std::cout<<index<<"\n";
    
    std::sort(arr,arr+size);
    int index1=bs(arr,size,element);
    std::cout<<index1;
    return 0;
}