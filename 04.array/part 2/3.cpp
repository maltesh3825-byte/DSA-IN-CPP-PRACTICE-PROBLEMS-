//max sub array sum using BRUTE FORCE but with optimisation with O(n^2)
#include<iostream>
#include<climits>

using namespace std;

void printsubmax(int *arr,int n){
    int maxsum = INT_MIN;
    for(int start=0;start<n;start++){

        int currentsum=0;
        for(int end=start;end<n;end++)
        {
            currentsum+=arr[end];
            maxsum=max(maxsum, currentsum);
        }
      
    }
      cout<<"max sum = "<<maxsum;
}
int main(){
    int arr[]={1,2,-3,5,6};
    int n= sizeof(arr)/sizeof(int);

    printsubmax(arr,n);
    return 0;
    
}