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

int find(int x, vi &p) {
    if(p[x] >= 0)
        return p[x] = find(p[x], p);
    return x;
}

bool union_(int a, int b, vi &p) {
    a = find(a, p);
    b = find(b, p);
    if(a==b)    return false;
    if(p[a] < p[b]) p[b] = a;
    else if(p[a] > p[b]) p[a] = b;
    else {
        p[a] = b;
        p[b]--;
    }
    return true;
}

void solve() {
    ll n, w;
    cin >> n;
    vll x(n+1), y(n+1), k(n+1);
    vector<pair<ll, pair<int, int> > > edges; // {w, {u, v}}
    FOR(i, 1, n+1) cin >> x[i] >> y[i];
    FOR(i, 1, n+1) {
        cin >> w;
        edges.pb(mp(w, mp(0, i)));
    }
    FOR(i, 1, n+1) cin >> k[i];
    FOR(i, 1, n+1)
        FOR(j, i+1, n+1)
            edges.pb(mp((k[i]+k[j])*(llabs(x[i]-x[j])+llabs(y[i]-y[j])), mp(i, j)));
    sort(edges.begin(), edges.end());
    // Kruskals MST algorithm
    vi ps;
    vpii con;
    ll ans = 0;
    vi p(n+1, -1);
    for(auto e: edges) {
        if(union_(e.second.first, e.second.second, p)) {
            ans += e.first;
            if(e.second.first == 0)
                ps.pb(e.second.second);
            else
                con.pb(e.second);
        }
    }
    cout << ans << endl;
    cout << ps.size() << endl;
    for(int s: ps) cout << s << " ";
    cout << endl << con.size() << endl;
    for(auto p: con) cout << p.first << " " << p.second << endl;
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