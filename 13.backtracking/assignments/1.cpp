//rat in maze
#include<iostream>
using namespace std;



int maze(int arr[][10],int r,int c,int n,int m,string ans){
    
    if(r==n-1&&c== m-1){
        cout<<ans<<"\n";
        return 1;
    }
    if(r>=n||c>= m||r<0||c<0||arr[r][c]==0){
        return 0;
    }

    int w1=0,w2=0,w3=0,w4=0;
    arr[r][c]=0;
    w1=maze(arr,r,c+1,n,m,ans+'R');//right
    w2=maze(arr,r+1,c,n,m,ans+'D');//down
    w3=maze(arr,r,c-1,n,m,ans+'L');//left
    w4=maze(arr,r-1,c,n,m,ans+'U');//up

    arr[r][c]=1;//backtrack
    
    return w1+w2+w3+w4;
}
int main(){
    string ans="";
    int arr[][10]= {{1,1,1,0},
                    {1,1,1,1},
                    {1,0,1,0},
                    {0,1,1,1}};
    cout<<maze(arr,0,0,4,4,ans);
    return 0;
}