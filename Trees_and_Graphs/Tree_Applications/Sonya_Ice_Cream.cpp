#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define FORk(i,a,b,k) for(int i=(a); i<(b); i+=k)
#define RFOR(i,a,b) for(int i=(a); i>=(b); i--)
#define RFORk(i,a,b,k) for(int i=(a); i>=(b); i-=k)
#define pb push_back
#define umap unordered_map
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef long long int ll;
typedef unsigned long long int  ull;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef queue<int> qi;
typedef stack<int> si;
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
typedef vector<pii> vpii;
#define sz(x) (int((x).size()))
const int MOD = 1e9+7;

umap<int, int> a[100001];
bool vis[100001];
int n,k,u,v,d;

pii dfs(int s) {
    vis[s] = true;
    pii dis;
    int md = 0, node = s;
    for(auto p: a[s]) {
        if(!vis[p.first]) {
            dis = dfs(p.first);
            if(dis.second+p.second > md) {
                md = dis.second+p.second;
                node = dis.first;
            }
        }
    }
    return mp(node, md);
}

pii dia_nodes() {
    FOR(i,0,n+1) vis[i] = false;
    pii p1 = dfs(1);
    FOR(i,0,n+1) vis[i] = false;
    pii p2 = dfs(p1.first);
    return mp(p1.first, p2.first);
}

bool dfs_path(int s, int d, vi &dp, vi &md) {
    vis[s] = true;
    if(s == d) {
        dp.pb(d);
        return true;
    }
    bool idp = false;
    for(auto e: a[s]){
        if(!vis[e.first]) {
            if(dfs_path(e.first, d, dp, md)) {
                dp.pb(s);
                idp = true;
            }
            else
                md[s] = max(md[s], e.second+md[e.first]);
        }
    }
    return idp;
}

void solve() {
    cin >> n >> k;    
    FOR(i, 0, n-1) {
        cin >> u >> v >> d;
        a[u][v] = d;
        a[v][u] = d;
    }
    pii dn = dia_nodes();
    // cout << dn.first << " " << dn.second << endl;
    FOR(i, 0, n+1) vis[i] = false;
    vi dp, md(n+1, 0);
    dfs_path(dn.first, dn.second, dp, md);
    // for(auto i: dp) cout << i << " " << md[i] << endl;
    int ds = dp.size(), mmd = *max_element(md.begin(), md.end());
    vi left(ds, 0), right(ds, 0);
    FOR(i, 1, ds)
        left[i] = max(md[dp[i]], left[i-1]+a[dp[i]][dp[i-1]]);
    RFOR(i, ds-2, 0)
        right[i] = max(md[dp[i]], right[i+1]+a[dp[i]][dp[i+1]]);
    int r = min(k, ds), ans = INT_MAX;
    FOR(i, 0, ds-r+1)
        ans = min(ans, max(mmd, max(left[i], right[i+r-1])));
    cout << ans;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}