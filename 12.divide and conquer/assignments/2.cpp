//merge sort
#include<iostream>
#include<vector>
using namespace std;
int merge(int arr[],int si,int mid,int ei){
    int i=si;
    int j=mid+1;
    int invcount=0;
    vector <int> temp;
    while(i<=mid&&j<=ei){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
            invcount+=(mid-i+1);
        }
    }
    while(i<=mid){
            temp.push_back(arr[i++]);
    }
    while(j<=ei){
        temp.push_back(arr[j++]);

    }
    //copying temp to orrignal array
    for(int idx=si,k=0;idx<=ei;idx++){
        arr[idx]=temp[k++];        
    }

    return invcount;
}
int mergesort(int arr[],int si,int ei){
    if(si>=ei){
        return 0;
    }
    int mid=si+(ei-si)/2;
   int left= mergesort(arr,si,mid);//left
    int right=mergesort(arr,mid+1,ei);//right
    
    int cross =merge(arr,si,mid,ei);
    return left+right+cross;
}
void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n=6;
    int arr[n]={6,3,7,5,2,4};
    int inversion=mergesort(arr,0,n-1);
    printArr(arr,n);
    cout<<"\ninversion:"<<inversion;
    return 0;
}