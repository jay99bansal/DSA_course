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

int phi(int n) {
    int ans = n;
    for(int i=2; i*i<=n; i++) {
        if(n%i == 0) {
            while(n%i == 0)
                n /= i;    
            ans = ans - ans/i;
        }
    }
    if(n>1) ans = ans-ans/n;
    return ans;
}

bool is_prime(int n) {
    if(n==1) return false;
    if(n==2) return true; 
    for(int i=2; i*i<=n; i++) 
        if(n%i == 0)
            return false;
    return true;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n+1);
    FOR(i,1,n+1)  cin >> a[i];
    vi pre(n+1, 0);
    FOR(i,1,n+1) {
        pre[i] = pre[i-1];
        if(is_prime(phi(a[i])))
            pre[i]++;
    }
    int l,r;
    FOR(i,0,q) {
        cin >> l >> r;
        cout << pre[r] - pre[l-1] << endl;
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