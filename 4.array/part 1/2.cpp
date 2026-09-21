//reverse array with extra space
#include<iostream>
using namespace std;
int main(){
    int arr[]={4,6,2,5,8};
    int n= sizeof(arr)/sizeof(int);
    int cop[n];
    for(int i=0;i<n;i++)
    {
        int j=n-i-1;
        cop[i]=arr[j];
    }
    
    for(int i=0;i<n;i++){
        arr[i]=cop[i];
    }
     for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
    return 0;

}