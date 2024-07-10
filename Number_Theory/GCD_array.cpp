#include<bits/stdc++.h>
using namespace std;

int f_gcd(int a, int b) {
    if(b==0)
        return a;
    return f_gcd(b, a%b);
}

class Solution {
public:
    int findGCD(vector<int> &nums) {
        return f_gcd(*max_element(nums.begin(), nums.end()), *min_element(nums.begin(), nums.end()));
    }
};