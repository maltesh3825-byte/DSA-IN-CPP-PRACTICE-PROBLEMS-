//binary search
#include<iostream>
using namespace std;
int bin(int *arr,int n,int key){
    int high=n-1;
    int low=0;
    while(low<=high ){
        int mid= (low+high)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            low=mid+1;
            
        }
        else if(arr[mid]>key){
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[]={2,4,7,8,14,17,25};
    int n =sizeof(arr)/sizeof(int);
    cout<<bin(arr,n,17);
    return 0;
}