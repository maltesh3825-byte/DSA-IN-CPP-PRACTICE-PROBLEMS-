//print subarrays
#include<iostream>
using namespace std;
int printar(int *arr,int n){
    int start,end;
    for(start=0;start<n;start++){
        for(end=start;end<n;end++){
            for(int i=start;i<=end;i++){
                cout<<arr[i];
            }
         cout<<",";   
        }
         cout<<"\n";

    }
}
int main(){
    int arr[]={1,2,3,4,};
    int n= sizeof(arr)/sizeof(int);
    cout<<printar(arr,n);
    return 0;
}