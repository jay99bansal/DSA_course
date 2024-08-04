#include<iostream>
#include<vector>
using namespace std;

const int N = 86028121;
bool arr_prime[N+1];
vector<int> vec_primes;

void sieve() {
    for(int i=2; i<N+1; i++) // fill the array of primes with true
        arr_prime[i] = true;
    
    for(int i=2; i*i<=N; i++) //apply the sieve algo
        if(arr_prime[i])
            for(int j=i*i; j<=N; j+=i) 
                arr_prime[j] = false;
    vec_primes.push_back(0);
    
    for(int i=2; i<N+1; i++)//update the vector of prime with the prime index
        if(arr_prime[i])
            vec_primes.push_back(i);
}

void solve() {
    int k;
    cin >> k;
    cout << vec_primes[k] << endl;
}

int main() {
    int t = 1;
    cin >> t;
    sieve();
    while(t--) {
        solve();//for each value of testcase from input, output the kth prime value
    }
    return 0;
}


//C++ 
/*
Problem Statement/Link: (CW) https://www.spoj.com/problems/TDKPRIME/
Finding the Kth Prime #sieve-of-eratosthenes

Input
An integer stating the number of queries Q(equal to 50000), and Q lines follow, each containing one integer K between 1 and 5000000 inclusive.

Output
Q lines with the answer of each query: the Kth prime number.

Sample Input:
7
1
10
100
1000
10000
100000
1000000

Expected Output:
2
29
541
7919
104729
1299709
15485863
By Jay Bhansal
*/
