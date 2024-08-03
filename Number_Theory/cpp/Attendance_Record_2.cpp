typedef long long ll;
const int mod = 1e9+7;

typedef struct {
    ll m[6][6];
}matrix;

matrix mul(matrix a, matrix b) {
    matrix c;
    for(int i=0; i<6; i++) {
        for(int j=0; j<6; j++) {
            c.m[i][j] = 0;
            for(int k=0; k<6; k++) {
                c.m[i][j] = (c.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
            }
        }
    }
    return c;
}

matrix pow(matrix a, int b) {
    if(b==1) return a;
    matrix ans = pow(a, b/2);
    ans = mul(ans, ans);
    if(b%2!=0) ans = mul(ans, a);
    return ans;
}

class Solution {
public:
    int checkRecord(int n) {
        matrix m {{
            {1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 1},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0},
        }};
        if(n==1) return 3;
        if(n==2) return 8;
        m = pow(m, n-2);
        return (8*m.m[0][0] + 3*m.m[0][1] + m.m[0][2] +
                4*m.m[0][3] + 2*m.m[0][4] + m.m[0][5])%mod;
    }
};