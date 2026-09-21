#include<iostream>
using namespace std;
class complex{
    int real;
    int img;
public:
    complex(int r,int i){
        real =r;
        img=i;
    }
    void showNum(){
        cout<<real<<"+"<<img<<"i\n";

    }
    //operator overloading
    complex operator +(complex &c2){
        int resreal=this->real+c2.real;
        int resimg=this->img+c2.img;
        complex c3(resreal,resimg);
        c3.showNum();
    }
};
int main(){
    complex c1(2,3);
    complex c2(2,1);
    c1+c2;
    return 0;

}