#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'substrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING n as parameter.
 */

int substrings(string n) {
    long long MOD = 1e9+7, si = n[0]-'0', sni=0, ni=1;
    for(int i=1; i<n.length(); i++) {
        sni = (sni + si) % MOD;
        si = (si*10 + (n[i]-'0')*(ni+1)) % MOD;
        ni++;
    }
    return (sni + si) % MOD;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
