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

const int N = 3000;
// Stores smallest prime factor
int sp[N+1];

void sieve() {
    sp[0] = 0;
    sp[1] = 1;
    FOR(i,1,N+1) sp[i] = i;
    for(int i=2; i*i<N+1; i++)
        if(sp[i] == i)
            FORk(j, i*i, N+1, i)
                if(sp[j] == j)
                    sp[j] = i;
}

void solve() {
    int n;
    cin >> n;
    int lp1, lp2, cn, ans=0; // last prime factors, current number, answer
    FOR(i,2,n+1) {
        cn = i;
        lp1 = lp2 = 1;
        while(cn != 1) {
            if(lp1 == 1)
                lp1 = sp[cn];
            else if(lp1 != sp[cn] && lp2 == 1)
                lp2 = sp[cn];
            else if(lp1 != sp[cn] && lp2 != sp[cn])
                break;
            cn /= sp[cn];
        }
        if(cn==1 && lp1!=1 && lp2!=1) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    sieve();
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}