#include<iostream>
using namespace std;

int sum(int mat[3][3]){
    int sum=0;
    for(int j=0;j<3;j++){
        sum+=mat[1][j];
    }
    return sum;
}

int main(){
    int mat[3][3]= {{1,4,9},{11,4,3},{2,2,3}};
    cout<<sum(mat);
}