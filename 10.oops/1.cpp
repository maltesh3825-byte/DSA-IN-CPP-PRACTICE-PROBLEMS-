//copy constructor
#include<iostream>
using namespace std;
class car {
    public:
        string name;
        string color;
        int *milege;
    car (string name,string color){
        this->name=name;
        this->color=color;
        milege = new int;
        *milege = 10;
    }
    car (car &original){
        name = original.name;
        color = original.color;
        milege = new int;
        *milege = *original.milege;
    }
};
int main(){
    car c1("kia","red");
    car c2(c1);
    cout<<c2.name<<endl;
    cout<<c2.color<<endl;
    cout<<*c2.milege<<endl;
    *c2.milege = 12;
    cout<<*c1.milege<<endl;
    cout<<*c2.milege<<endl;


}