#include<bits/stdc++.h>
using namespace std;

class Solution {
    int N;
    vector<vector<int>> al;
    vector<int> sz, dis;
    vector<bool> vis;

    void dfs(int node) {
        vis[node] = true;
        for(auto c: al[node]) {
            if(!vis[c]) {
                dfs(c);
                sz[node] += sz[c];
                dis[node] += dis[c] + sz[c];
            }
        }
        sz[node] ++;
    }

    void dfs2(int node, int p, int dp) {
        dis[node] = dis[node] + dp + N - sz[node];
        vis[node] = true;
        for(auto c: al[node])
            if(!vis[c]) 
                dfs2(c, node, dis[node]-dis[c]-sz[c]);
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        al.resize(n), sz.resize(n), dis.resize(n), vis.resize(n);
        for(auto e: edges) {
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }
        dfs(0);
        vis.assign(n, false);
        dfs2(0, 0, 0);
        return dis;
    }
};