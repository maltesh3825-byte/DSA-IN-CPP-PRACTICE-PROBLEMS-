//tiling problem
#include<iostream>
using namespace std;
int tp(int n){
    if(n==0||n==1){
        return 1;
    }
    return tp(n-1)+tp(n-2);
}
int main(){
cout<< tp(5);
   return 0;
}