#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n = 1000;

    // Step 1
    vector<bool> pr(n + 1, true);
    pr[0] = pr[1] = false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (pr[i]) {
            for (int j = i * i; j <= n; j += i) {
                pr[j] = false;
            }
        }
    }

    // Step 2
    vector<int> prs;
    for (int i = 2; i <= n; ++i) {
        if (pr[i]) {
            prs.push_back(i);
        }
    }

    // Step 3
    vector<bool> cb(n + 1, false);
    for (int i = 0; i < prs.size() - 1; ++i) {
        int ele = prs[i] + prs[i + 1] + 1;
        if (ele > n) {
            break;
        }
        if (pr[ele]) {
            cb[ele] = true;
        }
    }

    // Step 4
    int k;
    cin >> n >> k;
    int c = 0;
    for (int i = 2; i <= n; ++i) {
        if (cb[i]) {
            c++;
        }
    }

    if (c >= k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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

