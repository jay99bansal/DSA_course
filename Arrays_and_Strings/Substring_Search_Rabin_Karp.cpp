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

const int P = 31;
const int Pi = 129032259;

void solve() {
    string t,p;
    cin >> t >> p;
    int n = t.length(), m=p.length();
    if(m>n) return;
    ll hash_pattern = 0, hash_text=0, pp=1;
    FOR(i,0,m) {
        hash_pattern = (hash_pattern+(p[i]-'a'+1)*pp)%MOD;
        hash_text = (hash_text+(t[i]-'a'+1)*pp)%MOD;
        pp = (pp*P)%MOD;
    }
    if(hash_pattern == hash_text) cout << "0 ";
    FOR(i,m,n) {
        hash_text = (hash_text-(t[i-m]-'a'+1)+(t[i]-'a'+1)*pp)%MOD;
        hash_text = (hash_text*Pi)%MOD;
        if(hash_pattern == hash_text) cout << i-m+1 << " ";
    }
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