//convert numbers to words
#include<iostream>
using namespace std;
string words[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void convert(long long n){
    if(n==0){
        return ;
    }
    int lastdigit=n%10;
    convert(n/10);
    cout<<words[lastdigit]<<" ";
}
int main(){
    convert(9481725177);
    return 0;
}