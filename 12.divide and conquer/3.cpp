//search in left sorted array
#include<iostream>
using namespace std;
int search(int arr[],int si,int ei,int tar){
    if(si>ei){
        return -1;

    }
    int mid=si+(ei-si)/2;
    if(arr[mid]==tar){
        return mid;
    }
    if(arr[si]<=arr[mid]){
        if(arr[si]<=tar&&tar<=arr[mid]){
            return search(arr,si,mid-1,tar);//left side
        }
        else{
            return search(arr,mid+1,ei,tar);//right side

        }
    }
    else{
        if(arr[mid+1]<=tar&&tar<=arr[ei]){
            return search(arr,mid+1,ei,tar);

        }
        else{
            return search(arr,si,mid-1,tar);

        }
    }
}
int main(){
    int n=7;
    int arr[n]={4,5,6,7,0,1,2};
    cout<<search(arr,0,n,0);
    return 0;
}