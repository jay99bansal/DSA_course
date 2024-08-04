#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        for(auto n: nums) x^=n;
        for(int i=0; i<=nums.size(); i++) x^=i;
        return x;
    }
};