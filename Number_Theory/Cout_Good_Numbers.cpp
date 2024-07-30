/*
const int mod = 1e9+7;

long long pow(int a, long long b) {
    if(b==0)    return 1;
    long long ans = pow(a, b/2);
    ans = (ans*ans)%mod;
    if(b%2!=0) ans = (ans*a)%mod;
    return ans;
}

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long op = n/2, ep = n-op;
        return (pow(4, op)*pow(5, ep))%mod;
    }
};
*/
#include<iostream>
using namespace std;

class Solution {
public:
    long long mod = 1000000007;
    
    long long power(long long x, long long y) {   
        if (y == 0) return 1;
        long long ans = power(x, y/2);
        ans *= ans;
        ans %= mod;
        if (y % 2) ans *= x;
        ans %= mod;
        return ans;
    }
    
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n/2 + n % 2;
        return (power(5, even) * power(4, odd)) % mod;
    }
};

int main() {
    Solution s;
    long long n = 50;
    cout << s.countGoodNumbers(n);
}

//C++ 
/*
Problem Statement/Link: (HW)https://leetcode.com/problems/count-good-numbers/

Example 1:
Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".

Example 2:
Input: n = 4
Output: 400

Example 3:
Input: n = 50
Output: 564908303
 
Constraints:
1 <= n <= 10^15

By Jay Bhansal
*/
