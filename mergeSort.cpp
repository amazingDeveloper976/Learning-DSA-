#include<iostream>
void printArr(int* arr,int n){
    for(int i=0;i<n;i++){
        std::cout<<"Index "<<i<<" is"<<arr[i]<<"\n";
    }
    std::cout<<"\n\n";
}
void merge(int* a,int low,int mid,int high){
    int i=low,j=mid+1,k=low,b[high+1];
    while(i<=mid&&j<=high){
        if(a[i]<a[j]){
            b[k]=a[i];
            k++;i++;
        }
        else{
            b[k]=a[j];
            k++;j++;
        }
    }
    while(j<=high){
        b[k]=a[j];
        k++;j++;
    }
    while(i<=mid){
        b[k]=a[i];
        k++;i++;
    }
    for(i=low;i<=high;i++){
        a[i]=b[i];
    }
 
}
void mergeSort(int* a,int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
int main(){
    int a[]={7,74,3,6,2};
    int m=sizeof(a)/sizeof(int);
    //printArr(c,m+n);
    mergeSort(a,0,m-1);
    printArr(a,m);
    return 0;
}