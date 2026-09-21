#include<iostream>
using namespace std;
class Complex{
    int real;
    int img;
public:
    Complex(int r,int i){
        real =r;
        img=i;
    }
    void ShowNum(int real,int img){
        cout<<real<<"+"<<img<<"i\n";
    }
    Complex operator - (Complex &c2){
        int resreal = this->real-c2.real;
        int resimg =this->img-c2.img;
        ShowNum(resreal,resimg); 

    }
};
int main(){
    Complex c1(4,2);
    Complex c2(2,1);
    c1-c2;
    return 0;
}
