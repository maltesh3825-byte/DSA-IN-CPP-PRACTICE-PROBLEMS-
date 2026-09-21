//single level inheritance
#include<iostream>
using namespace std;
class animal{
    void drink(){
        cout<<"drnk";
    }
    public:
    void eat(){
        cout<<"eat\n";
    }

};
class fish:protected animal{
    public:
    void swim(){
            eat();

        cout<<"swim";

    }
};
int main(){
    fish f1;
    f1.swim();
    // f.eat();
    // f.drink();
}

