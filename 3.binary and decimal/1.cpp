//binary to decimal

#include<iostream>
using namespace std;
int bin(int a){
       int n,sum=0;
        int pow=1;
        n= a;
    while(n>0){
        int lastdig =n%10;
        sum+=pow*lastdig;
        pow*=2;
        n/=10;
    }
    cout<<"decimal of "<<a<<" : "<<sum;
}
int main(){
    bin(1111);
}