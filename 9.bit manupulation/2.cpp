//check ith bit
#include<iostream>
using namespace std;
int check(int n,int i){
    int bitmask= 1<<i;
    if (!(n&bitmask)){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){
    int n=6;
    int i =3;
    cout<<check(n,i);
    return 0;
    
}