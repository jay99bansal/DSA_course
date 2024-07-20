#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0, n=nums.size();
        vector<vector<int>> ans;
        while(i<n-2) {
            int j=i+1, k=n-1;
            while(j<k) {
                if(nums[j]+nums[k]>-nums[i]) k--;
                else if(nums[j]+nums[k]<-nums[i]) j++;
                else {
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    ans.push_back(v);
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            }
            i++;
            while(i<n-2 && nums[i]==nums[i-1]) i++;
        }
        return ans;
    }
};