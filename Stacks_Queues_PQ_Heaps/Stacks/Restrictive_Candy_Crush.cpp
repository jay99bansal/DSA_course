#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    string Reduced_String(int k,string s){
        // Your code goes here
        stack<pair<char, int>> st;
        for(auto c: s) {
            if(!st.empty() && st.top().first == c) {
                pair<char, int> p = st.top();
                p.second++;
                st.pop();
                st.push(p);
            }
            else 
                st.push(make_pair(c, 1));
            if(!st.empty() && st.top().second == k)
                st.pop();
        }
        string ans;
        while(!st.empty()) {
            pair<char, int> p = st.top();
            while(p.second--) ans += p.first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }


};