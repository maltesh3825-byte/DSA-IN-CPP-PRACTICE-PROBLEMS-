//program to find a key in sorted matrix by staircase method
#include<iostream>
using namespace std;
int search(int mat[][4],int n, int m,int key){
    int i=0,j=m-1;
    while(i<n &&j>=0){
        if(key==mat[i][j]){
            cout<<"key found at "<<i<<" "<<j;
            return 0;
        }
        else if(key<mat[i][j]){
            j--;
        }
        else{
            i++;
        }

    }
    cout<<"key not found";
    return 0;
}

int main(){
    int mat[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};\
    search(mat,4,4,13);
    return 0;
}