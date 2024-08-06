#include <iostream>
using namespace std;

double pow(double a, long b) {
    if(b==0)
        return 1.0;
    double ans = pow(a, b/2);
    ans = ans*ans;
    if(b%2==1)  ans = ans*a;
    return ans;
}

class Solution {
public:
    double myPow(double x, int n) {
        long nn = n;
        if(n>=0) return pow(x, nn);
        else return 1.0/pow(x,-nn);
    }
};

int main () {
    double x;
    int n;
    cin >> x >> n;
    
    Solution sol;
    cout << sol.myPow(x,n);

    return 0;
}

/*
Problem Statement/Link: (CW) https://leetcode.com/problems/powx-n/description/

Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

 

Constraints:

    -100.0 < x < 100.0
    -231 <= n <= 231-1
    n is an integer.
    Either x is not zero or n > 0.
    -104 <= xn <= 104


By Jay Bhansal
*/