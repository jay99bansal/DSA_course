#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fix_down(vector<int> &nums, int p, int n) {
        int l = p, lc = 2*p+1, rc = 2*p+2;
        if(lc <= n && nums[l] < nums[lc])
            l = lc;
        if(rc <= n && nums[l] < nums[rc])
            l = rc;
        if(l!=p) {
            swap(nums[l], nums[p]);
            fix_down(nums, l, n);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // Heapify O(n)
        for(int i=n/2-1; i>=0; i--) {
            fix_down(nums, i, n-1);
        }

        // Heap Sort
        for(int r=n-1; r>0; r--) {
            swap(nums[0], nums[r]);
            fix_down(nums, 0, r-1);
        }

        return nums;
    }
};