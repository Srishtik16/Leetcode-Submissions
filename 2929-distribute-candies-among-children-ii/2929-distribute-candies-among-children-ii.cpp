class Solution {
public:
    long long distributeCandies(int n, int limit) {
        // a + b + c = n
        // b + c = n - a
        // for all values of n - a, find b + c ways
        long long ways = 0;
        for(int i = 0; i <= limit; i++) {
            int goal = n - i;
            if(goal < 0) {
                continue;
            }
            if(limit >= goal) {
                ways += goal + 1;
            }
            else {
                ways += max(0, 2 * limit - goal + 1);
            }
        }
        return ways;
    }
};