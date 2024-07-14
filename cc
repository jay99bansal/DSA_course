#include<bits/stdc++.h>
using namespace std;

const int N = 1000000;
vector<int> phi(N+1);
vector<int> sp(N+1);

void phi_1_to_n(int n) {
    for(int i=0; i<=n; i++) phi[i] = i;
    for(int i=0; i<=n; i++) sp[i] = i;
    for(int i=2; i<=n; i++) {
        if(phi[i] == i) {
            for(int j = i; j<=n; j++) {
                phi[j] -= phi[j]/phi[i];
                if(sp[j] == j)  sp[j] = i;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    long long ans = 0;
    long long lp = -1;
    while(n!=1) {
        if(lp!=sp[n]) {
            lp = sp[n];
            ans += lp*phi[lp];
        }
        n/=lp;
    }
    cout << (ans+1)*n/2 << endl;
}

int main() {
    int t;
    cin >> t;
    phi_1_to_n(N);
    while(t--) {
        solve();
    }
    return 0;
}