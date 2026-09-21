//program to find the key in a sorted matrix
#include<iostream>
using namespace std;
int search(int mat[][4],int n,int m,int key){
    int i,j;
   
    for(i=0;i<n;i++){
        int start =0;
  
        int end=m-1;
        
        while(start<=end){
            int mid=(start+end)/2;
        if(mat[i][mid]==key){
            cout<<"key found at "<<i+1<<" "<<mid+1;
            return 0;
        }
        else if(mat[i][mid]<key){
            start=mid+1;

        }
        
        else if(mat[i][mid]>key){
            end=mid-1;

        }
    }
        
       
        
    } 
    cout<<"key not found";
    return 0;
}

int main(){
    int mat[4][4]={{1,2,3,4},
                   {5,6,7,8},
                   {9,10,11,12},
                   {13,14,15,16}};
    search(mat,4,4,16);
    return 0;
}
