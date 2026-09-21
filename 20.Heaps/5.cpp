//heap sort
#include<iostream>
#include<queue>
using namespace std;
void heapify(int i,vector<int> &arr,int n){
    int l=2*i +1;
    int r=2*i +2;
    int maxI=i;
    if(l<n && arr[l]<arr[maxI]){//for asscending order just change the sign in the two if condn
        maxI=l;
    }
    if(r<n && arr[r]<arr[maxI]){
        maxI=r;
    }

    if(maxI!=i){
        swap(arr[i],arr[maxI]);
        heapify(maxI,arr,n);
    }
}
void heapsort(vector<int> &arr){
    int n=arr.size();
    for(int i=(n/2)-1;i>=0;i--){
        heapify(i,arr,n);
    }

    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(0,arr,i);
    }
}
int main(){
    vector<int> arr={1,4,2,5,3};
    heapsort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}