//buy and sell stocks with O(n+n) = O(2n) = O(n)
#include<iostream>
#include<climits>
using namespace std;
void maxprof(int *prices,int n){
    int bestbuy[100000];

    bestbuy[0]=INT_MAX;
    cout<<"best buy = ";
    for(int i=1;i<n;i++){

        bestbuy[i]=min(bestbuy[i-1],prices[i-1]);
        cout<<bestbuy[i]<<",";
    }
    cout<<endl;
        
    int maxprof=0;
    
    
    for(int i=0;i<n;i++){

        int curprof=prices[i]-bestbuy[i];
        maxprof=max(curprof,maxprof);
    }
    cout<<"maxprofit = "<<maxprof<<"\n";

}

int main(){
    int arr[]={7,1,5,3,2,9};
    int n=sizeof(arr)/sizeof(int);
    maxprof(arr,n);
    return 0;
}