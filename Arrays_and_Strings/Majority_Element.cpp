#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0, x;
        for(auto n: nums) {
            if(c==0) {
                c = 1;
                x = n;
            }
            else if(n==x) c++;
            else c--;
        }
        c = 0;
        for(auto n: nums) if(n==x) c++;
        if(c>nums.size()/2) return x;
        return -1;
    }
};