//pair sum 146
#include<iostream>
#include<vector>
using namespace std;
vector<int> pairsum(vector<int> arr,int target){
    int cursum=0;
    vector<int> ans;
    int start = 0;
    int end = arr.size()-1;
    while(start<end){
        cursum=arr[start]+arr[end];
        if(cursum==target){
        ans.push_back(start);
        ans.push_back(end);
        return ans;
        }
        else if(cursum>target){
            end--;
        }
        else{start++;}
    }
    return ans;
}

int main(){
    vector<int> arr={2,7,11,15};
    int target =9;
    vector<int> ans=pairsum(arr,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}