//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int lcmOfArray(int N , int A[]) {
        int M = 1000000007;
        int lcm = A[0];
        for(int i=1; i<N; i++)
            lcm = ((long long)(A[i])*lcm/__gcd(lcm, A[i]))%M;
        return lcm;
    }
};

//{ Driver Code Starts.
int main() {
    int N;
    cin >> N;
    int A[N];

    for(int i=0 ; i<N ; i++)
        cin >> A[i];
    
    Solution ob;
    cout << ob.lcmOfArray(N,A) << endl;
    return 0;
}
// } Driver Code Ends

/*
Problem Statement/Link: (HW) https://www.geeksforgeeks.org/problems/lcm-of-given-array-elements3919/1

Input:
N = 4
A = {1 , 2 , 8 , 3}
Output:
24
Explanation:
LCM of the given array is 24.
24 % 1000000007 = 24

Input:
N = 2
A = {1 , 8}
Output:
8
Explanation:
LCM of the given array is 8.


Your Task:
You don't need to read input or print anything. Your task is to complete the function lcmOfArray() which takes an Integer N and an Array A as input and returns the answer.

Expected Time Complexity: O(N*log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= A[i] <= 105

By Jay Bhansal
*/