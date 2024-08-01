#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()>haystack.length())   return -1;
        int j;
        for(int i=0; i<=haystack.length()-needle.length(); i++) {
            for(j=0; j<needle.length(); j++) {
                if(haystack[i+j] != needle[j])
                    break;
            }
            if(j==needle.length()) return i;
        }
        return -1;
    }
};