//x power n using logn
#include<iostream>
using namespace std;
int pow(int x,int n){
    if(n==0){
        return 1;
    }
    int pows=pow(x,n/2);
    int powsquare=pows*pows;
    if(n%2!=0){
        return x*powsquare;
    }
    return powsquare;
}
int main(){
    cout<<pow(2,4);
    return 0;
}