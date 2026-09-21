//set the ith bit
/*
Set bit → n | (1 << i)

Clear bit → n & ~(1 << i)

Get bit → n & (1 << i)

Update bit → clear then set
*/

#include<iostream>
using namespace std;
int set(int n,int i){
    int bitmask=1<<i;
    return bitmask|n;
} 
int main(){
    int n=6;
    int i =3;
    cout<<set(n,i);
    return 0;
}