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

/*
Problem Statement/Link: (CW) https://www.codechef.com/problems/COZIE

Golu and Sweetness

 

Golu and his friend are busy preparing dishes for the winners of this contest. There are N dishes in the menu.
Golu assigns a sweetness factor to each dish. His friend is curious about this sweetness factor and decides to ask him Q queries about that.

In each query, he asks Golu to count the number of numbers in range [l,r] whose sweetness factor is a prime number.

Sweetness Factor of a number A is defined as the number of positive integers B, satisfying the following 2 conditions:
     1 <= B <= A and
     A * B = lcm(A,B)

 
Input

First line consists of 2 integers, N and Q.
The next line contains N integers each representing a dish.
Then Q lines follow each containing 2 integers, l and r.

 
Output

For each Query, output the number of numbers having sweetness factor as a prime number in a new line.

 
Constraints
1 <= N,Q <= 100000
All the N numbers are positive integers between 0 and 1000000000
All the queries and the array indices are 1-based.

 
Example

Input:
3 2
3 2 1
1 2
2 3
Output:
1
0


By Jay Bhansal
*/