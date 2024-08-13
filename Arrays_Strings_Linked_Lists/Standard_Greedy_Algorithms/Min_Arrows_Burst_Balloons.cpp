#include<bits/stdc++.h>
using namespace std;

class comp {
    public:
    bool operator()(vector<int> &v1, vector<int> &v2) {
        return v1[1] < v2[1];
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp()); // Sort on finish time

        int c = points[0][1], ans=1;
        for(int i=0; i<points.size(); i++) {
            if(points[i][0] > c) {
                c = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};