#include<iostream>
#include<memory>
struct Node{
    int data;
    std::unique_ptr<struct Node> left;
    std::unique_ptr<struct Node> right;
};
 std::unique_ptr<struct Node> createNode(int data){
    std::unique_ptr<struct Node> n= std::make_unique<struct Node>();
    //or like this: cpp assigns value acc to struct's fields 
    //std::unique_ptr<struct Node> n= std::make_unique<struct Node>(Node{data,nullptr,nullptr});
    n->data=data;
    n->left=nullptr;
    n->right=nullptr;
    return n;
}
struct Node* search(struct Node* n,int val){
    while(n!=nullptr){
        if(n->data==val){
            std::cout<<"Found\n";
            return n;
        }
        else if(val<n->data){
            n=(n->left).get();
            std::cout<<"Left\n";
        }
        else{ n=(n->right).get();std::cout<<"Right\n"; }
    }
    std::cout<<"Not found\n";
    return nullptr;
}
struct Node* search2(struct Node* ptr,int val){
    if(ptr==nullptr){
        return nullptr;
    }
    if(ptr->data==val){
        std::cout<<"Found\n";
        return ptr;
    }
    else if(val< ptr->data){
        std::cout<<"Left\n";
        return search2((ptr->left).get(),val);
    }
    else{
         std::cout<<"Right\n";
        return search2((ptr->right).get(),val);
    }
}

int main(){
    std::unique_ptr<struct Node> root=createNode(10);
    std::unique_ptr<struct Node> n1=createNode(8);
    std::unique_ptr<struct Node> n2=createNode(11);
    std::unique_ptr<struct Node> n3=createNode(7);
    std::unique_ptr<struct Node> n4=createNode(9);
    n1->left=std::move(n3);   //firstly, bottom nodes should be built
    n1->right=std::move(n4);
    root->left=std::move(n1);
    root->right=std::move(n2);
    std::cout<<search(root.get(),9)<<"\n";
    std::cout<<search2(root.get(),9)<<"\n";
    return 0;
}