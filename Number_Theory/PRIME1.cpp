
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
const int msm = 31623;
bool pr[msm+1], p[100001];
vi prs;
void sieve() {
    // Step 1
    FOR(i, 2, msm+1)
        pr[i] = true;
    for(int i=2; i*i<=msm; i++)
        if(pr[i])
            FORk(j, i*i, msm+1, i)
                pr[j] = false;
    FOR(i, 2, msm+1)
        if(pr[i])
            prs.pb(i);
}
void seg_sieve(int N, int M) {
    // Step 2 & 3
    FOR(i,0,M-N+1)  p[i] = true;
    if(N==1) p[0] = false; // Border case
    int sm = int(sqrt(M));
    for(auto i: prs) {
        if(i>sm)
            break;
        int x = (N/i)*i;
        if(x < N)
            x += i;
        if(x < i*i)
            x = i*i;
        FORk(j, x, M+1, i) {
            p[j-N] = false;
        }
    }
    FOR(i, 0, M-N+1)
        if(p[i])
            cout << N+i << endl;
}

void solve() {
    int n,m;
    cin >> n >> m;
    seg_sieve(n,m);
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    sieve();
    while(t--) {
        solve();
    }
    return 0;
}
