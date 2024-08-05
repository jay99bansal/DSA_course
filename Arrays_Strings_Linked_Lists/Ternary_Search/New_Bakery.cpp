#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define FORk(i,a,b,k) for(int i=(a); i<(b); i+=k)
#define RFOR(i,a,b) for(int i=(a); i>=(b); i--)
#define RFORk(i,a,b,k) for(int i=(a); i>=(b); i-=k)
#define pb push_back
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long int ll;
typedef unsigned long long int  ull;
typedef vector<ll> vll;
typedef vector<ull> vull;
const int MOD = 1e9+7;

ll pr(ll n, ll a, ll b, ll k) {
    return k*b-(k*(k-1))/2+(n-k)*a;
}

ll ts(ll n, ll a, ll b, ll l, ll r) {
    if(r-l < 3) {
        ll ans = 0;
        FOR(i, l, r+1) ans = max(ans, pr(n, a, b, i));
        return ans;
    }
    ll m1 = l + (r-l)/3;
    ll m2 = r - (r-l)/3;
    ll p1 = pr(n, a, b, m1);
    ll p2 = pr(n, a, b, m2);
    if(p1 < p2) return ts(n, a, b, m1, r);
    if(p1 > p2) return ts(n, a, b, l, m2);
    return ts(n, a, b, m1, m2);
}

void solve() {
    ll n,a,b;
    cin >> n >> a >> b;
    cout << ts(n, a, b, 0, min(n,b)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}