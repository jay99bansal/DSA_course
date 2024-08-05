//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector<int> calc_z(string s) {
            int n = s.length();
            vector<int> z(n, 0);
            int L=0, R=0;
            for(int i=1; i<n; i++) {
                if(i>R) {
                    L = R = i;
                    while(R<n && s[R-L] == s[R])
                        R++;
                    z[i] = R-L;
                    R--;
                }
                else {
                    if(z[i-L]+i <= R)
                        z[i] = z[i-L];
                    else {
                        L = i;
                        while(R<n && s[R-L] == s[R])
                            R++;
                        z[i] = R-L;
                        R--;
                    }
                }
            }
            return z;
        }
        
        vector <int> search(string pat, string txt) {
            string ns = pat + "#" + txt;
            vector<int> z = calc_z(ns);
            vector<int> ans;
            for(int i=0; i<z.size(); i++)
                if(z[i] == pat.length())
                    ans.push_back(i-pat.length());
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends