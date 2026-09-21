//bubble sort O(n^2)
#include<iostream>
using namespace std;
int print(int *arr,int n){
     for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}
void bubble(int *arr,int n){
    for(int i=0;i<n-1;i++){
        bool swapped = false;

        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped) break;  // stop if already sorted
    }
   print(arr,n);
}

int main(){
    int arr[]={3,4,2,5,1};
    int n =sizeof(arr)/sizeof(int);
    bubble(arr,n);
    return 0;

}