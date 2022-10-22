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
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 1;
        fenwick_tree ft(n + 1);
        for(int i = 0; i < n; i++) {
            ft.update(i, nums[i]);
        }
        for(int i = 1; i < n; i++) {
            int l = 0, r = i - 1, ans = i;
            while(l <= r) {
                int mid = (l + r) / 2;
                long long s = ft.query(i - 1) - ft.query(mid - 1);
                int len = i - 1 - mid + 1;
                long long need = len * 1LL * nums[i] - s;
                if(need <= k) {
                    ans = mid;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            res = max(res, i - ans + 1);
        }
        return res;
    }
};