#include<iostream>
void printArr(int* arr,int n){
    for(int i=0;i<n;i++){
        std::cout<<"Index "<<i<<" is"<<arr[i]<<"\n";
    }
    std::cout<<"\n\n";
}
void bubbleSort(int* arr,int n){
    int temp;
    bool sorted=0; //to make this adaptive
    for(int i=0;i<n-1;i++){//n-1 because n-1 is no of passes
        sorted=1;
        std::cout<<"Pass number "<<i+1<<"\n";
        for(int j=0;j<n-1-i;j++){ //for comparision in each pass
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                sorted=0;
            }
        }
        if (sorted){
            return;
        }
    }
}
int main(){
    //int arr[]={1,6,9,3,5,8,0};
    int arr[]={163,283,302,419,572,772,628};
    int n=sizeof(arr)/sizeof(int);
    printArr(arr,n);
    bubbleSort(arr,n);
    printArr(arr,n);
    return 0;
}