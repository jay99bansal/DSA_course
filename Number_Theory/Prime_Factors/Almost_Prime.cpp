#include<iostream>
#include<vector>
using namespace std;

const int N = 1000;
// Stores smallest prime factor
int sp[N+1];

void sieve() {
    sp[0] = 0;
    sp[1] = 1;
    //FOR(i,1,N+1) sp[i] = i;
    for(int i=2; i<N+1; i++)
        sp[i] = i;
    for(int i=2; i*i<N+1; i++)
        if(sp[i] == i)
            //FORk(j, i*i, N+1, i)
            for(int j = i*i; j<N+1; j+=i)
                if(sp[j] == j)
                    sp[j] = i;
}

void solve() {
    int n;
    cin >> n;
    int lp1, lp2, cn, ans=0; // last prime factors, current number, answer
    //FOR(i,2,n+1) {
    for(int i = 2; i<n+1; i++) {
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

    int t = 1;
    sieve();
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}


//C++ 
/*
Problem Statement/Link: (HW) https://codeforces.com/problemset/problem/26/A

Input
The first line of the input contains two integers n (2 ≤ n ≤ 1000) and k (0 ≤ k ≤ 1000).

Output
Output YES if at least k prime numbers from 2 to n inclusively can be expressed as it was described above. Otherwise output NO.

Sample Input1:
27 2

Expected Output1:
YES

Sample Input2:
45 7

Expected Output2:
NO

By Jay Bhansal
*/

