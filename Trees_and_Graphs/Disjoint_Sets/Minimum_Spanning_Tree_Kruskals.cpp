//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int p[1001];
    
    int find(int x) {
        if(p[x]>=0)
            return p[x] = find(p[x]);
        return x;
    }
    
    bool union_(int a, int b) {
        int pa = find(a), pb = find(b);
        int ra = -p[pa], rb = -p[pb];
        if(pa == pb) return false;
        if(ra>rb)
            p[pb] = pa;
        else if(rb > ra)
            p[pa] = pb;
        else {
            p[pa] = pb;
            p[pb]--;
        }
        return true;
    }
    
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // adj:
        // [0]: {{1, 5}, {2, 1}}
        // [1]: {{0, 5}, {2, 3}}
        // [2]: {{0, 1}, {1, 3}}
        vector<pair<int, pair<int, int>>> edges; //<w, <u, v>>
        for(int i=0; i<V; i++) {
            p[i] = -1;
            for(auto e: adj[i]) 
                edges.push_back({e[1], {i, e[0]}});
        }
        sort(edges.begin(), edges.end());
        int ans = 0;
        for(auto e: edges) {
            if(union_(e.second.first, e.second.second))
                ans += e.first;
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends