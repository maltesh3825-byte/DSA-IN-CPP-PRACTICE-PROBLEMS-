//multi - level inheritance
#include<iostream>
using namespace std;
class animal{ 
public:
        void eat(){
            cout<<"eat\n";
        }
};
class mammals:public animal{
public:
        void blood(){
            cout<<"warm\n";
        }

};
class dog : public mammals{
public:
        void bark(){
            cout<<"barks\n";
        }
};
int main (){
    dog d;
    d.eat();
    d.blood();
    d.bark();
}