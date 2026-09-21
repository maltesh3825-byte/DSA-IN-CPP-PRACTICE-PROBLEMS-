//allocating 2d array dynamically
#include<iostream>
using namespace std;
int main(){
    int rows,columns;
    cin>>rows;
    cin>>columns;
    int ** mat=new int*[rows];
    for(int i=0;i<rows;i++){
        mat[i]=new int[columns];

    }
    int x=1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            mat[i][j]=x;
            cout<<mat[i][j];
            x++;
        }
        cout <<endl;
    }
}