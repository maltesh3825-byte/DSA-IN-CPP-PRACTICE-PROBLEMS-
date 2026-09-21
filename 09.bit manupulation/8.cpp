//fast exponentiation
#include<iostream>
using namespace std;
int expo(int x,int n){
    int ans=1;
    while(n>0){
        int lastbit=n&1;
        if(lastbit){
            ans=ans*x;
        }
        x=x*x;
        n=n>>1;
    }
    return ans;

}
int main(){
    cout<<expo(3,5);
    return 0;
}