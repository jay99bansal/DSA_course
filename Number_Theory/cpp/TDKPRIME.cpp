#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define FORk(i,a,b,k) for(int i=(a); i<(b); i+=k)
#define RFOR(i,a,b) for(int i=(a); i>=(b); i--)
#define RFORk(i,a,b,k) for(int i=(a); i>=(b); i-=k)

const int N = 86028121;
bool pr[N+1];
vector<int> prs;

void sieve() {
    FOR(i,2,N+1) pr[i] = true;
    for(int i=2; i*i<=N; i++) 
        if(pr[i])
            for(int j=i*i; j<=N; j+=i) 
                pr[j] = false;
    prs.push_back(0);
    FOR(i, 2, N+1)
        if(pr[i])
            prs.push_back(i);
}

void solve() {
    int k;
    cin >> k;
    cout << prs[k] << endl;
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