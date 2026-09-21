//max sub array sum using BRUTE FORCE with O(n^3)
#include<iostream>
#include<climits>

using namespace std;

void printsubmax(int *arr,int n){
    int maxsum = INT_MIN;
    for(int start=0;start<n;start++){
        
        for(int end=start;end<n;end++)
        {
            int currentsum=0;
            for(int i=start;i<=end;i++){
                currentsum+=arr[i];
            }
            cout<<currentsum<<",";
            maxsum=max(maxsum, currentsum);
        }
        cout<<endl;
      
    }
      cout<<"max sum = "<<maxsum;
}
int main(){
    int arr[]={1,2,-3,5,6};
    int n= sizeof(arr)/sizeof(int);

    printsubmax(arr,n);
    return 0;
    
}