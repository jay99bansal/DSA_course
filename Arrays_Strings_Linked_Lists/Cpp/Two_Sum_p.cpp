#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> vals;
        for(int i=0; i<nums.size();  i++) {
            vals.push_back({nums[i], i});
        }
        sort(vals.begin(), vals.end());
        int i=0, j=vals.size()-1;
        while(i<j) {
            if(vals[i].first + vals[j].first < target) i++;
            else if(vals[i].first + vals[j].first > target) j--;
            else return vector<int> {vals[i].second, vals[j].second};
        }
        return vector<int>{};
    }
};
