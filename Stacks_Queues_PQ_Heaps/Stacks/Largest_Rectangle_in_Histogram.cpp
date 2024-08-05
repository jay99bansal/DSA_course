#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> nsel(vector<int> &nums) {
        vector<pair<int, int>> ans;
        stack<pair<int, int>> s;
        for(int i=0; i<nums.size(); i++) {
            while(!s.empty() && s.top().first >= nums[i]) s.pop();
            if(s.empty()) ans.push_back(make_pair(-1, -1));
            else ans.push_back(s.top());
            s.push(make_pair(nums[i], i));
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> rHeights;
        for(int i=heights.size()-1; i>=0; i--)  rHeights.push_back(heights[i]);
        vector<pair<int, int>> l = nsel(heights), r=nsel(rHeights);
        reverse(r.begin(), r.end());
        int ans = 0;
        for(int i=0; i<heights.size(); i++) {
            int val = heights[i]*(heights.size()-r[i].second-l[i].second-2);
            ans = max(ans, val);
        }
        return ans;
    }
};