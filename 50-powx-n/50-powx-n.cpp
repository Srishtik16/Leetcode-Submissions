class Solution {
public:
    double fastPow(double x, int n) {
        double res = 1.0;
        while(n > 0) {
            if(n & 1) {
                res *= x;
            }
            x *= x;
            n >>= 1;
        }
        return res;
    }
    double myPow(double x, int n) {
        if(n < 0) {
            return 1.0 / fastPow(x, abs(n));
        }
        else {
            return fastPow(x, n);
        }
    }
};