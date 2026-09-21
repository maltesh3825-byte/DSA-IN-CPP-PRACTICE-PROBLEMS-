//clear the ith bit
#include<iostream>
using namespace std;
int clear(int n,int i){
    int bitmask= ~(1<<i);
    return n & bitmask;
}
int main(){
    int n=2;
    int i =1;
    cout<<clear(n,i);
    return 0;

}