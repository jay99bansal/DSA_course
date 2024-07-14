double pow(double a, long b) {
    if(b==0)
        return 1.0;
    double ans = pow(a, b/2);
    ans = ans*ans;
    if(b%2==1)  ans = ans*a;
    return ans;
}

class Solution {
public:
    double myPow(double x, int n) {
        long nn = n;
        if(n>=0) return pow(x, nn);
        else return 1.0/pow(x,-nn);
    }
};
