#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        vector<int>fre(nums.size()+1,0);
        
        vector<int>mismatch;
        for(int i=0;i<nums.size();i++){
           fre[nums[i]]++;
        }

        int dup,missing;

        for(int i=1;i<=nums.size();i++){
            if(fre[i]==2){
                dup=i;
            }

            if(fre[i]==0){
                missing=i;


            }
        }
                       
        mismatch.push_back(dup);
        mismatch.push_back(missing);

        
        return mismatch;
        
    }
};
int main(){
    vector<int>nums={1,2,2,4};
    Solution obj;
    vector<int>ans=obj.findErrorNums(nums);
    cout<<"dup"<<"="<<ans[0]<<endl;
    cout<<"miss"<<"="<<ans[1];
    return 0;

}