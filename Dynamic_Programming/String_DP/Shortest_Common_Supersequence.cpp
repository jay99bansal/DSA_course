#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        int dp[m+1][n+1];
        dp[0][0] = 0;
        for(int i=1; i<=m; i++) dp[i][0] = i;
        for(int i=1; i<=n; i++) dp[0][i] = i;
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = 1+min(dp[i][j-1], dp[i-1][j]);
            }
        }
        cout << dp[m][n];
        int i=m, j=n;
        string ans = "";
        while(i!=0 && j!=0) {
            if(str1[i-1] == str2[j-1]) {
                ans += str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] < dp[i][j-1]) {
                ans += str1[i-1];
                i--;
            }
            else {
                ans += str2[j-1];
                j--;
            }
        }
        while(i!=0) {
            ans += str1[i-1];
            i--;
        }
        while(j!=0) {
            ans += str2[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};