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

int main() {
    vector<int> nums;
    int input;
    
    while (cin >> input)
        nums.push_back(input);
    
    Solution sol;
    sol.isGoodArray(nums) ? cout << "true" : cout << "false";
    return 0;
}


/*
Problem Statement/Link: (HW) https://leetcode.com/problems/check-if-it-is-a-good-array/description/

Example 1:

Input: nums = [12,5,7,23]
Output: true
Explanation: Pick numbers 5 and 7.
5*3 + 7*(-2) = 1

Example 2:

Input: nums = [29,6,10]
Output: true
Explanation: Pick numbers 29, 6 and 10.
29*1 + 6*(-3) + 10*(-1) = 1

Example 3:

Input: nums = [3,6]
Output: false

 

Constraints:

    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^9


By Jay Bhansal
*/

