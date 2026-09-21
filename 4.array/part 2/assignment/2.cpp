// lc 33 search in sorted left rotated array
#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size()-1;
        int start=0;
        int end=n;
        while(start<=end){
            int mid=(start+end)/2;
            if(target==nums[mid]){
                return mid;
            }
            if(nums[start]<=nums[mid]){
               if(target>=nums[start]&&target<nums[mid]){
                    end=mid-1;
               }
               else{
                start=mid+1;
               }

            }
            else{
                if(target>nums[mid]&&target<=nums[end]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }


            }
        }
         return -1;
        
    }
};
int main(){
    Solution s1;
    vector<int> arr ={4,5,6,7,0,1,2,3};
    cout<<s1.search(arr,2);
    return 0;
}