class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n);
        pref[0] = nums[0];
        map<long long, vector<int>> index;
        index[pref[0]].push_back(0);
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
            if(i == n - 1) {
                continue;
            }
            index[pref[i]].push_back(i);
        }
        long long sum = pref.back();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int delta = k - nums[i];
            if((sum + delta) & 1) {
                continue;
            }
            int c1 = lower_bound(index[(sum + delta) / 2].begin(), index[(sum + delta) / 2].end(), i) - index[(sum + delta) / 2].begin();
            int ind = lower_bound(index[(sum + delta) / 2 - delta].begin(), index[(sum + delta) / 2 - delta].end(), i) - index[(sum + delta) / 2 - delta].begin();
            int c2 = index[(sum + delta) / 2 - delta].size() - ind;
            ans = max(ans, c1 + c2);
        }
        int cnt = 0;
        for(int i = 1; i < n; i++) {
            if(pref[i - 1] == pref.back() - pref[i - 1]) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};