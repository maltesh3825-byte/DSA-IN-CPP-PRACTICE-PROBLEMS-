//check for power of 2
#include<iostream>
using namespace std;
int check(int n){
    if(!(n&(n-1))){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    
    cout<<check(4)<<endl;
    cout<<check(7)<<endl;
    cout<<check(17)<<endl;
    cout<<check(32)<<endl;
    return 0;
}