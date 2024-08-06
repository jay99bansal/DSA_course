#include <iostream>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;

typedef struct {
    ll m[6][6];
}matrix;

matrix mul(matrix a, matrix b) {
    matrix c;
    for(int i=0; i<6; i++) {
        for(int j=0; j<6; j++) {
            c.m[i][j] = 0;
            for(int k=0; k<6; k++) {
                c.m[i][j] = (c.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
            }
        }
    }
    return c;
}

matrix pow(matrix a, int b) {
    if(b==1) return a;
    matrix ans = pow(a, b/2);
    ans = mul(ans, ans);
    if(b%2!=0) ans = mul(ans, a);
    return ans;
}

class Solution {
public:
    int checkRecord(int n) {
        matrix m {{
            {1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 1},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0},
        }};
        if(n==1) return 3;
        if(n==2) return 8;
        m = pow(m, n-2);
        return (8*m.m[0][0] + 3*m.m[0][1] + m.m[0][2] +
                4*m.m[0][3] + 2*m.m[0][4] + m.m[0][5])%mod;
    }
};

int main() {
    int n;
    cin >> n;

    Solution sol;
    cout << sol.checkRecord(n);

    return 0;
}

/*
Problem Statement/Link: (HW) https://leetcode.com/problems/student-attendance-record-ii/description/

An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

    'A': Absent.
    'L': Late.
    'P': Present.

Any student is eligible for an attendance award if they meet both of the following criteria:

    The student was absent ('A') for strictly fewer than 2 days total.
    The student was never late ('L') for 3 or more consecutive days.

Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.

 

Example 1:

Input: n = 2
Output: 8
Explanation: There are 8 records with length 2 that are eligible for an award:
"PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).

Example 2:

Input: n = 1
Output: 3

Example 3:

Input: n = 10101
Output: 183236316

 

Constraints:

    1 <= n <= 105


By Jay Bhansal
*/
