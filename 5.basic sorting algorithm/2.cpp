//selection sort
#include<iostream>
using namespace std;
void print(int*arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
}
int selection(int *arr,int n){
    for(int i=0;i<=n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            
            if(arr[j]<arr[min]){
               min=j;

            }
            
        }
         swap(arr[i],arr[min]);
    }
    print(arr,n);
}
int main(){
    int arr[]={5,4,2,1,3};
    int n=sizeof(arr)/sizeof(int);
    selection(arr,n);
    return 0;
}