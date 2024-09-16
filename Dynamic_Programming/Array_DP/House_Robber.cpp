#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        int l = max(nums[1], nums[0]), sl = nums[0], tmp;
        for(int i=2; i<n; i++) {
            tmp = max(l, sl+nums[i]);
            sl = l;
            l = tmp;
        }
        return l;
    }
};