//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int lcmOfArray(int N , int A[]) {
        int M = 1000000007;
        int lcm = A[0];
        for(int i=1; i<N; i++)
            lcm = ((long long)(A[i])*lcm/__gcd(lcm, A[i]))%M;
        return lcm;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout<<ob.lcmOfArray(N,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends