//Question2:Writeafunctiontocalculatethesumofdigitsofanumber.
#include<iostream>
using namespace std;
int rev(int n){
    int sum =0;
    while(n>0){
        int lastdig=n%10;
         sum= sum+lastdig;
         n=n/10;
    }
    return sum;
}
int main()
{
    cout<<rev(134);
}