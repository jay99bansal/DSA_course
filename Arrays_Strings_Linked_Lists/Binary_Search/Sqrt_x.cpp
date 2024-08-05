class Solution {
public:
    int bs(long l, long r, long x) {
        if(l == r-1)
            return l;
        long m = (l+r)/2;
        if(m*m > x)
            return bs(l, m, x);
        else
            return bs(m, r, x);
    }

    int mySqrt(int x) {
        return bs(0, (long)x+1, x);
    }
};