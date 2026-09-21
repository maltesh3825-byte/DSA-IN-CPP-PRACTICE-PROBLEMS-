//max sub array sum using KADANE'S ALGORITHM with O(n)
#include<iostream>
#include<climits>

using namespace std;

void printsubmax(int *arr,int n){
    int maxsum = INT_MIN;
    int currentsum=0;
    for(int i=0;i<n;i++){
        
        currentsum+=arr[i];
        maxsum=max(maxsum, currentsum);
        if(currentsum<0){
            currentsum=0;
        }  
    }
      cout<<"max sum = "<<maxsum;
}
int main(){
    int arr[]={-8,-4,-3,-2,-1};
    int n= sizeof(arr)/sizeof(int);

    printsubmax(arr,n);
    return 0;
    
}