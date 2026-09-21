//majority element
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void MajorityElement(vector<int> nums){
    unordered_map<int,int>m;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(m[nums[i]]){
            m[nums[i]]++;
        }
        else{
            m[nums[i]]=1;
        }
    }
    for(pair<int,int> p : m){
        if(p.second>n/3){
            cout<<p.first<<" ";        }
    }
}
int main(){
    vector<int> arr={1,2,3,5,1,2,5,1,3,1};
    vector<int> arr2={1,2};

    MajorityElement(arr2);
    return 0;

}