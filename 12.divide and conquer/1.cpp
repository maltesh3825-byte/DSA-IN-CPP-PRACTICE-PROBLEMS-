//merge sort
#include<iostream>
#include<vector>
using namespace std;
void merge(int arr[],int si,int ei,int mid){
    int i=si;
    int j=mid+1;
    vector <int> temp;
    while(i<=mid&&j<=ei){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
            temp.push_back(arr[i++]);
    }
    while(j<=ei){
        temp.push_back(arr[j++]);

    }
    //copying temp to orrignal array
    for(int idx=si,i=0;idx<=ei;idx++){
        arr[idx]=temp[i++];        
    }

    
}
void mergesort(int arr[],int si,int ei){
    while(si>=ei){
        return ;
    }
    int mid=si+(ei-si)/2;
    mergesort(arr,si,mid);//left
    mergesort(arr,mid+1,ei);//right
    
    merge(arr,si,ei,mid);
}
void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}
int main(){
    int n=6;
    int arr[n]={6,3,7,5,2,4};
    mergesort(arr,0,n-1);
    printArr(arr,n-1);
    return 0;
}