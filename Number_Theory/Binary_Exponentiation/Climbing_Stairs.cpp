typedef struct {
    long long v11, v12, v21, v22;
} matrix;

matrix identitiy() {
    return matrix {1, 0, 1, 1};
}

matrix mul(matrix a, matrix b) {
    return matrix {a.v11*b.v11+a.v12*b.v21,
                   a.v11*b.v21+a.v12*b.v22,
                   a.v21*b.v11+a.v22*b.v21,
                   a.v21*b.v21+a.v22*b.v22};
}

matrix pow(matrix a, int b) {
    if(b==1)    return a;
    matrix ans = pow(a, b/2);
    ans = mul(ans, ans);
    if(b%2!=0)  ans = mul(ans, a);
    return ans;
}

class Solution {
public:
    int climbStairs(int n) {
        matrix fib = matrix{1, 1, 1, 0};
        if(n==1) return 1;
        if(n==2) return 2;
        matrix fibn = pow(fib, n-2);
        return 2*fibn.v11 + fibn.v12;
    }
};