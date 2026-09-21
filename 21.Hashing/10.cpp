//largest subarray with sum 0
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int largestSubarray(vector<int> v){
    unordered_map<int,int> m;
    int ans=0;
    int sum=0;
    for(int j=0;j<v.size();j++){
        sum+=v[j];
        if(m.count(sum)){
            int currlen=j-m[sum];
            ans=max(currlen,ans);
        }
        else{
            m[sum]=j;
        }
    }
    return ans;
}
int main(){
    vector<int> v={15,2,-2,-8,1,7,10};
    cout<<"max subarray : "<<largestSubarray(v);
    return 0;
}
