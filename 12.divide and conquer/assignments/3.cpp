//169
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            // If count is 0, we pick the current number as our new candidate
            if (count == 0) {
                candidate = num;
            }
            
            // If the current number matches the candidate, kingdom grows
            // If it's different, they fight and count drops
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};
int main(){
    vector <int> arr={2,2,2,1,1,1,2,2};
    Solution s1;
    cout<<s1.majorityElement(arr);
    return 0;

    
}