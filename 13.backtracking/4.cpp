//grid ways
#include<iostream>
using namespace std;
int grid(int r,int c,int n,int m,string ans){
    if(r==n-1&&c==m-1){
        cout<<ans<<"\n";
        return 1;
    }
    if(r==n||c==m){
        return 0;
    }
    int w1=grid(r,c+1,n,m,ans+'R');//right
    int w2=grid(r+1,c,n,m,ans+'D');//down
    return w1+w2;
}
int main(){
    string ans="";
    cout<<grid(0,0,3,3,ans);
    return 0;

}