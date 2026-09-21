//program to find the transpose of the matrix
#include<iostream>
using namespace std;
int transpose(int mat[][3],int n,int m){
    int mat2[3][2];
    int k=3;
    int l=2;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            swap(mat[i][j],mat2[j][i]);
        }
    }
     for(int i=0;i<k;i++){
        for(int j=0;j<l;j++){
            cout<<mat2[i][j];
        }
        cout<<endl;
    }
    return 0;
}
int main(){
    int mat[][3]={{1,2,3},{4,5,6}};
    int n=2,m=3;
    int mat2[3][2];
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j];
        }
        cout<<endl;

    }
    transpose(mat,2,3);

}