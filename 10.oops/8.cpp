//friend class and function use 
#include<iostream>
using namespace std;
class A{
    string secret="secret data\n";
    friend class B;
    friend void sec(A &obj);
};
class B{
public:
    void showsecret(A &obj){
        cout<<obj.secret;
    }

};
void sec(A &obj){
    cout<<obj.secret;
}
int main(){
    A a1;
    B b1;
    b1.showsecret(a1);
    sec(a1);
    return 0;
}