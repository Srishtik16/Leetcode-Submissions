const int MOD = 1e9 + 7;
class fenwick_tree{
private:
    vector<long long> BIT;
public:
    fenwick_tree(int n){
        BIT.resize(n + 1, 0);
    }
    long long query(int i){
        long long res = 0;
        while(i >= 0){
            res += BIT[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
    void update(int i, int val){
        while(i < BIT.size()){
            BIT[i] += val;
            i = (i | (i + 1));
        }
    }
};
class Solution {
public:
    long long fastPow(long long x, int n) {
        long long res = 1;
        while(n > 0) {
            if(n & 1) {
                res *= x;
                res %= MOD;
            }
            x *= x;
            x %= MOD;
            n >>= 1;
        }
        return res % MOD;
    }
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        int mx = *max_element(nums.begin(), nums.end());
        fenwick_tree ft(mx + 1);
        long long ans = 0;
        for(auto x: nums) {
            int l = x;
            int r = min(target - x, mx);
            if(r < l) {
                ft.update(x, 1);
                continue;
            }
            int pw = ft.query(r) - ft.query(l - 1);
            ans += fastPow(2, pw);
            ans %= MOD;
            ft.update(x, 1);
        }
        return ans;
    }
};