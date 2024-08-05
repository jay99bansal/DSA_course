#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char cob(char c) {
        if(c == ')')    return '(';
        if(c == '}')    return '{';
        return '[';
    }
    bool isValid(string s) {
        stack<char> st;
        for(auto c: s) {
            if(c=='(' || c=='{' || c=='[')
                st.push(c);
            else if(!st.empty() && st.top()==cob(c))
                st.pop();
            else
                return false;
        }
        if(st.empty())  return true;
        return false;
    }
};