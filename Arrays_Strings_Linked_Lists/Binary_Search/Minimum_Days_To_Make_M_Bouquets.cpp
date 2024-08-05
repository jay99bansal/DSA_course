//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // At xth day returns the maximum no of 
    // bouquets you can make
    int nb(vector<int> &bd, int k, int x) {
        int mc = 0, ans = 0;
        for(auto b: bd) {
            if(b<=x) mc++;
            else mc = 0;
            if(mc == k) {
                ans++;
                mc = 0;
            }
        }
        return ans;
    }
    int bs(vector<int> &bd, int m, int k, int l, int r) {
        if(l == r) 
            return l;
        int mid = (l+r)/2;
        int s = nb(bd, k, mid);
        if(s < m)
            return bs(bd, m, k, mid+1, r);
        else
            return bs(bd, m, k, l, mid);
    }
    int solve(int M, int K, vector<int> &bloomDay) {
        if(bloomDay.size()/K < M) return -1;
        return bs(
            bloomDay, M, K, 1, 
            *max_element(
                bloomDay.begin(),
                bloomDay.end()
            )
        );
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends