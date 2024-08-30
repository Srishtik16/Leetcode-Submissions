
class fenwick_tree{
private:
    unordered_map<long long, long long> BIT;
public:
    fenwick_tree(long long n){
        BIT.clear();
    }
    long long query(long long i){
        long long res = 0;
        while(i >= 0){
            res += BIT[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
    void update(long long i, long long val){
        while(i < (long long)1e12){
            BIT[i] += val;
            i = (i | (i + 1));
        }
    }
};
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<long long> a;
        for(auto &x: nums) {
            a.push_back(x + 1LL + INT_MAX);
        }
        fenwick_tree ft(n + 1);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            long long fullSum = ft.query(1e12 + 1);
            long long leftSum = ft.query(2LL * a[i] - 1LL - INT_MAX);
            ans += fullSum - leftSum;
            ft.update(a[i], 1);
        }
        return ans;
    }
};

// For a j, how many is can I get?
// Go left to right
// Full sum - sum(2 * nums[j])
// Try an implicit fenwick tree