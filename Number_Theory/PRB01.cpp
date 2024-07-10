#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define FORk(i,a,b,k) for(int i=(a); i<(b); i+=k)
#define RFOR(i,a,b) for(int i=(a); i>=(b); i--)
#define RFORk(i,a,b,k) for(int i=(a); i>=(b); i-=k)

void solve() {
    int n;
    cin >> n;
    if(n==1) {
        cout << "no" << endl;
        return;
    }
    if (n==2) {
        cout << "yes" << endl;
        return;
    }
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) {
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
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