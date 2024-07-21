#include<bits/stdc++.h>
using namespace std;

vector<int> meo(vector<int>& left, vector<int>& right) {
    vector<int> ans;
    int l=0, r=0;
    while(l<left.size() && r<right.size()) {
        if(left[l]%2==0) {
            ans.push_back(left[l]);
            l++;
        }
        else {
            ans.push_back(right[r]);
            r++;
        }
    }
    while(l<left.size()) {
        ans.push_back(left[l]);
        l++;
    }
    while(r<right.size()) {
        ans.push_back(right[r]);
        r++;
    }
    return ans;
}

vector<int> mseo(vector<int>& nums, int l, int r) {
    if(r==l) {
        vector<int> a = {nums[l]};
        return a;
    }
    int m = (l+r)/2;
    vector<int> left = mseo(nums, l, m);
    vector<int> right = mseo(nums, m+1, r);
    return meo(left, right);
}

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        return mseo(nums, 0, nums.size()-1);
    }
};