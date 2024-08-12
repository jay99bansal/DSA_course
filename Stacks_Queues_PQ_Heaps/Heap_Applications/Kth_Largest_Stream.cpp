#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int> pq;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto n: nums) {
            pq.push(-n); // Min-Heap
            if(pq.size()>k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(-val);
        if(pq.size() > k)
            pq.pop();
        return -pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */