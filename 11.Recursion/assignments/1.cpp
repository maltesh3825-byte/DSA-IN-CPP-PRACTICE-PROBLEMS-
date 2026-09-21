//binary through recursion
#include<iostream>
using namespace std;
int bin(int arr[],int key,int n,int start,int end){
    if(start>end){
        cout<<"no key found\n";
        return 0;
    }
    int mid=(start+end)/2;
    if(arr[mid]==key){
        return mid;

    }
    if(arr[mid]>key){
        return bin(arr,key,n,start,mid);
    }
    if(arr[mid]<key){
        return bin(arr,key,n,mid,end);
    }
}
int main(){
    int arr[]={1,2,3,4,5,6,7};
    cout<<bin(arr,5,7,0,7);
    return 0;
}