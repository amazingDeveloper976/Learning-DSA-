#include <iostream>
class array{
    public:
    int tSize,uSize;
    int* ptr;
    array(int tSize,int uSize){
        this->tSize=tSize;
        this->uSize=uSize;
        ptr=new int[uSize];
    }
    void set(){
        for(int i=0;i<uSize;i++){
            std::cout<<"Enter of #"<<i;
            std::cin>>*(ptr+i);
        }}
        void get(){
        for(int i=0;i<uSize;i++){
            std::cout<<*(ptr+i)<<"\n";
        }}
};

int main() {
    array arr1(20,3);
    arr1.set();
    arr1.get();
    return 0;
}