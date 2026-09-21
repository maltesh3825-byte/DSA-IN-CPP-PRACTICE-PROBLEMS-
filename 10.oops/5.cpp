#include<iostream>
using namespace std;
class parent{
public:
    virtual void show(){
        cout<<"parent class\n";
    }
};
class child:public parent{
    void show(){
        cout<<"child class\n";
    }
};
int main(){
    child child1;
    parent *ptr;//runtime binding
    ptr=&child1;//virtual function
    ptr->show();
    return 0;
}