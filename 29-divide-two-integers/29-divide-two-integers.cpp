class Solution {
public:
    long long divide(long long dividend, long long divisor) {
       return min(dividend/divisor,(1LL<<31)-1);
    }
};