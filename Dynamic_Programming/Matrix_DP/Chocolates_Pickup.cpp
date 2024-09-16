//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        long long dp[n][m][m];
        
        // Base Case
        for(int c1 = 0; c1<m; c1++) {
            for(int c2=0; c2<m; c2++) {
                if(c1 == c2) dp[n-1][c1][c2] = grid[n-1][c1];
                else dp[n-1][c1][c2] = grid[n-1][c1] + grid[n-1][c2];
            }
        }
        
        // Recurrence
        for(int r=n-2; r>=0; r--) {
            for(int c1=0; c1<m; c1++) {
                for(int c2=0; c2<m; c2++) {
                    dp[r][c1][c2] = INT_MIN;
                    for(int d1=-1; d1<=1; d1++)
                        for(int d2=-1; d2<=1; d2++)
                            if(c1+d1>=0 && c1+d1<m && c2+d2>=0 && c2+d2<m)
                                dp[r][c1][c2] = max(dp[r][c1][c2], dp[r+1][c1+d1][c2+d2]);
                    if(c1==c2)  dp[r][c1][c2] += grid[r][c1];
                    else dp[r][c1][c2] += (grid[r][c1] + grid[r][c2]);
                }
            }
        }
        
        // Ans
        return dp[0][0][m-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends