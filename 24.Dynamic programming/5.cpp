//0-1 knapsack problem by recursion
#include<iostream>
#include<vector>
using namespace std;
int knapSackRec(vector<int> val, vector<int> wt, int W, int n){
    if(n==0 || W==0){
        return 0;
    }
    int itmWt= wt[n-1];
    int itmVal = val[n-1];

    if(itmWt<=W){
        //include
        int ans1= knapSackRec(val,wt,W-itmWt, n-1) + itmVal;
        
        //exclude
        int ans2= knapSackRec(val,wt,W, n-1) ;
        
        return max(ans1, ans2);
    }
    else{
        //exclude   
        return knapSackRec(val, wt, W, n-1);
    }
}

int main(){
    vector<int> val ={15,14,10,45,30};
    vector<int> wt ={2,5,1,3,4};
    int n= 5;
    int W= 7;
    cout<<knapSackRec(val, wt, W, n);
}
