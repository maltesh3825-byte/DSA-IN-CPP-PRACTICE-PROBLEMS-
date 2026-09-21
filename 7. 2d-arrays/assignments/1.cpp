//to find the count of 7 in 2d matrix
#include<iostream>
using namespace std;
int count(int mat[][3],int n,int m,int key){
    int count=0;
    for(int i= 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==key){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int mat[][3]={
        {4,7,8},{8,8,7}
    };
    cout<<count(mat,2,3,7);

}