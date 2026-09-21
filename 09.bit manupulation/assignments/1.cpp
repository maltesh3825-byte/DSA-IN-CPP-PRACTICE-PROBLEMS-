//clear bits from i to j
#include<iostream>
using namespace std;
int clear(int n,int i,int j){
    for(int o=i;o<=j;o++){
        n=n & ~(1<<o);
    }
    return n;
}
int main(){
    cout<<clear(31,1,3);
    return 0;
}