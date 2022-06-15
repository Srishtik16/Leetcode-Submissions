class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        auto check = [&](int days) {
            vector<int> vis(n, 0);
            for(int i = 0; i < n; i++) {
                if(bloomDay[i] <= days) {
                    vis[i] = 1;
                }
            }
            int cnt = 0;
            vector<int> islands;
            for(auto x: vis) {
                if(x == 1) {
                    cnt++;
                }
                else {
                    if(cnt != 0) {
                        islands.push_back(cnt);
                    }
                    cnt = 0;
                }
            }
            if(cnt != 0) {
                islands.push_back(cnt);
            }
            int bouquets = 0;
            for(auto x: islands) {
                bouquets += x / k;
            }
            return bouquets >= m;
        };
        int l = 1, r = 1e9 + 5, ans = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(check(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};