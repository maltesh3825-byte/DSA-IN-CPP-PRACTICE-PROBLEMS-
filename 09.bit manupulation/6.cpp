#include<iostream>
using namespace std;
int con(int n,int i,int val){
    if(val==0){
        int mismatch = ~(1<<i);
        return n&mismatch;
    }
    else{
        return n|(1<<i);
    }
}
int main(){
    cout<<con(7,3,1);
    return 0;
}