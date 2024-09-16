#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size(); // mxn matrix
        vector<int> tmp(n, 0);
        vector<vector<int>> dp(m, tmp);
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(g[i][j] == 0) {
                    if(i==0 && j==0) dp[i][j] = 1;
                    else if(i==0) dp[i][j] = dp[i][j-1];
                    else if(j==0) dp[i][j] = dp[i-1][j];
                    else dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};