//insertion sort
#include<iostream>
using namespace std;

void print(int*arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}
void insertion(int *arr,int n){
    for(int i = 1;i<n;i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
    print(arr,n);
}

int main(){
    int arr[5]= {1,2,3,4,5};
    insertion(arr,5);
    return 0;
}