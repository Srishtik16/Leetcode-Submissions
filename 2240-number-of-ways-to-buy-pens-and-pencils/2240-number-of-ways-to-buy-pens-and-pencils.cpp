class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        for(int i = 0; i <= total; i += cost1) {
            long long pencils = (total - i) / cost2;
            ans += pencils + 1;
        }
        return ans;
    }
};