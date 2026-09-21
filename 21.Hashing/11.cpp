//k sum subarray count
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int  subarray(vector<int> v,int k){
    unordered_map<int,int>m;
    m[0]=1;
    int ans=0;
    int sum=0;
    for(int j=0;j<v.size();j++){
        sum+=v[j];
        if(m.count(sum-k)){
            ans+=m[sum-k];
        }
        if(m.count(sum)){
            m[sum]++;
        }
        else{
            m[sum]=1;
        }
    }
    return ans;
}
int main(){
    vector<int> v={1,2,3};
    cout<<"subarray sum of 3:"<<subarray(v,3);
    return 0;
}