//quick sort
#include<iostream>
using namespace std;
int partition(int arr[],int si,int ei){
    int i=si-1;
    int pivot=arr[ei];
    for(int j=si;j<ei;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    i++;
    swap(arr[i],arr[ei]);
    return i;

}
void quicksort(int arr[],int si,int ei){
    if(si>=ei){
        return ;
    }
    int pivotidx=partition(arr,si,ei);
    quicksort(arr,si,pivotidx-1);//left part
    quicksort(arr,pivotidx+1,ei);//right part
}
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}int main (){
    int n=6;
    int arr[n]= {6,3,7,5,2,4};
    quicksort(arr,0,n);
    printarr(arr,n);
    return 0;
}