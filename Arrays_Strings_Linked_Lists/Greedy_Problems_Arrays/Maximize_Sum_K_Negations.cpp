#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end()); // Build heap
        for(int i=0; i<k; i++) {
            int a = pq.top();
            pq.pop();
            pq.push(-a);
        }
        int ans = 0;
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};