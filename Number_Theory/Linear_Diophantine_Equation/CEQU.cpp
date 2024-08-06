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

int gcd(int a, int b){
    if(b==0)    return a;
    return gcd(b, a%b);
}
void solve() {
    int a,b,c,g;
    cin >> a >> b >> c;
    if(a>b) g = gcd(a,b);
    else g = gcd(b,a);
    if(c%g == 0)    cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    FOR(i,1,t+1) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}

/*
Problem Statement/Link: (CW) https://www.spoj.com/problems/CEQU/

Sample Input:
Input starts with an integer T (1<=T<=105) denoting the number of test cases. 
Each test case contains three integers a, b, and c. (1<=a, b, c<=106).
2
2 4 8
3 6 7

Expected Output:
For each test case of input print the case number and “Yes” if there exists at least one solution, print “No” otherwise.
Case 1: Yes
Case 2: No

By Jay Bhansal
*/
