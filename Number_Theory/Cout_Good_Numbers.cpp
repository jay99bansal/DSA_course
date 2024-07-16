const int mod = 1e9+7;

long long pow(int a, long long b) {
    if(b==0)    return 1;
    long long ans = pow(a, b/2);
    ans = (ans*ans)%mod;
    if(b%2!=0) ans = (ans*a)%mod;
    return ans;
}

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long op = n/2, ep = n-op;
        return (pow(4, op)*pow(5, ep))%mod;
    }
};