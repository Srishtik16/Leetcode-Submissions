class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> m;
        for(int i = 0; i < n; i++) {
            m[arr[i]].push_back(i + 1);
        }
        vector<long long> ans(n, -1);
        for(auto x: m) {
            int l = x.second.size();
            vector<int> a = x.second;
            vector<long long> pref(l), suff(l);
            pref[0] = a[0];
            suff[l - 1] = a[l - 1];
            for(int i = 1; i < l; i++) {
                pref[i] = pref[i - 1] + a[i];
            }
            for(int i = l - 2; i >= 0; i--) {
                suff[i] = suff[i + 1] + a[i];
            }
            for(int i = 0; i < l; i++) {
                long long val = 0;
                val += i * 1LL * a[i] - (i > 0 ? pref[i - 1] : 0);
                val += suff[i] - (l - i) * 1LL * a[i];
                ans[a[i] - 1] = val;
            }
        }
        return ans;
    }
};