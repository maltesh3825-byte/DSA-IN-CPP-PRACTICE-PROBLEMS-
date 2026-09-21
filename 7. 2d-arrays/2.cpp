//diagonal matrix sum O(n^2)
#include<iostream>
using namespace std;
int diag(int matrix[][3],int n,int m){
    int sum=0;

    for(int i = 0;i<n;i++){
       for(int j=0;j<n;j++){
         if(i==j){
            sum+=matrix[i][j];
        }
        else if(j==n-1-i){
            sum+=matrix[i][j];
        }
       }
    }
    cout<<sum;
}
/*O(n) tc codefor above
in diag()
{
for(int i =0;i<n;i++){
sum+=matrix[i][i]
if(i!=n-i-1){
sum+=matrix[i][n-i-1]}
}
}*/
int main(){
    int matrix[][3]={{1,2,3},{4,5,6},{7,8,9}};
    diag(matrix,3,3);
    return 0;
}