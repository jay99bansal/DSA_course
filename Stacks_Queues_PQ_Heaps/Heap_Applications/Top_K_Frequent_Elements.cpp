#include<bits/stdc++.h>
using namespace std;

class comp {
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second; // min heap on second values
    }
};

class Solution {
public:
    // Overall: T: O(n+k log d), S: O(d+k)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Frequency map
        // T: O(n), S: O(d)
        unordered_map<int, int> um;
        for(auto n: nums)
            um[n]++;
        
        // Build heap (Heapify)
        // T: O(klogk), S: O(k)
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        for(auto &[key, val]: um) {
            pq.push({key, val});
            if(pq.size() > k)
                pq.pop();
        }

        // Take the top k elements
        // T: O(k log d), S: O(k)
        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};