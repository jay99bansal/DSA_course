#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcd = nums[0];
        for(auto n: nums)
            gcd = __gcd(gcd, n);
        if(gcd == 1)
            return true;
        return false;
    }
};