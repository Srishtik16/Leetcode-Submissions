class Solution {
public:
    const int MOD = 1e9 + 7;
    long long modPow(long long x, int y) {
        long long res = 1;
        while(y > 0) {
            if(y & 1) {
                res = res * x;
                res %= MOD;
            }
            x = x * x;
            x %= MOD;
            y /= 2;
        }
        return res % MOD;
    }
    int numberOfGoodPartitions(vector<int>& nums) {
        map<int, int> f, l;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(f.find(nums[i]) == f.end()) {
                f[nums[i]] = i;
            }
            l[nums[i]] = i;
        }
        vector<pair<int,int>> v;
        for(auto x: f) {
            v.push_back({x.second, l[x.first]});
        }
        sort(v.begin(), v.end());
        int cnt = 0, end = -1;
        for(auto x: v) {
            if(end < x.first) {
                cnt++;
            }
            end = max(end, x.second);
        }
        return modPow(2, cnt - 1);
    }
};