#include <iostream>
using namespace std;

typedef struct {
    long long v11, v12, v21, v22;
} matrix;

matrix identitiy() {
    return matrix {1, 0, 1, 1};
}

matrix mul(matrix a, matrix b) {
    return matrix {a.v11*b.v11+a.v12*b.v21,
                   a.v11*b.v21+a.v12*b.v22,
                   a.v21*b.v11+a.v22*b.v21,
                   a.v21*b.v21+a.v22*b.v22};
}

matrix pow(matrix a, int b) {
    if(b==1)    return a;
    matrix ans = pow(a, b/2);
    ans = mul(ans, ans);
    if(b%2!=0)  ans = mul(ans, a);
    return ans;
}

class Solution {
public:
    int climbStairs(int n) {
        matrix fib = matrix{1, 1, 1, 0};
        if(n==1) return 1;
        if(n==2) return 2;
        matrix fibn = pow(fib, n-2);
        return 2*fibn.v11 + fibn.v12;
    }
};

int main() {
    int n;
    cin >> n;

    Solution sol;
    cout << sol.climbStairs(n);
    return 0;
}

/*
Problem Statement/Link: (CW) https://leetcode.com/problems/climbing-stairs/description/

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:

    1 <= n <= 45

By Jay Bhansal
*/