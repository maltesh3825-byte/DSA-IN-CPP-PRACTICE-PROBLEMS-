//decimal to binary

#include<iostream>
using namespace std;
int dec(int a){
    int n,r,sum=0;
    int pow= 1;
    n=a;
    while(n>0){
        r= n%2;
        sum= r*pow+ sum;
        pow*=10;
        n/=2;

    }
    cout<<"binary of "<<a<<" : "<<sum;
}
int main(){
    dec(15);
}
