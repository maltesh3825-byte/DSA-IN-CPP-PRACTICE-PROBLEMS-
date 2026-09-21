//count bits
#include<iostream>
using namespace std;
void count (int n){
    int counti=0;
    while(n>0){
        counti +=n&1;
        n=n>>1; 
    }
    cout<<counti<<endl;
}
int main(){
    count(15);
    return 0;

}