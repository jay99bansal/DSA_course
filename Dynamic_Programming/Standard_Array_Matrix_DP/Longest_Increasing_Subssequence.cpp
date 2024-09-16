#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = {nums[0]};
        for(int i=1; i<n; i++) {
            if(nums[i] > dp.back())
                dp.push_back(nums[i]);
            else {
                int low = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[low] = nums[i];
            }
        }
        return dp.size();
    }
};