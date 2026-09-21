//buy and sell stocks with O(n^2)
#include<iostream>
#include<climits>
using namespace std;
void maxprof(int *prices,int n){
    
    int curprof=0;
    int maxprof=0;
    int bestbuy[100000];

    bestbuy[0]=INT_MAX;
    cout<<"best buy = ";
    
    for(int sell=1;sell<n;sell++){

        bestbuy[sell]=min(bestbuy[sell-1],prices[sell-1]);
        cout<<bestbuy[sell]<<",";
        
        for(int buy=sell-1;buy>=0;buy--){
            curprof=prices[sell]-prices[buy];
            maxprof= max(curprof, maxprof);
        }
         
    }
    cout<<endl;
    cout<<"maxprofit = "<<maxprof<<"\n";

}

int main(){
    int arr[]={7,1,5,3,6,4};
    int n=sizeof(arr)/sizeof(int);
    maxprof(arr,n);
    return 0;
}