class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int l = 1, r = position.back() + 1, ans = -1;
        auto check = [&](int mid) {
            int curr = 0, cnt = 1;
            for(int i = 0; i < n; i++) {
                if(abs(position[curr] - position[i]) >= mid) {
                    curr = i;
                    cnt++;
                }
            }
            return cnt >= m;
        };
        while(l <= r) {
            int mid = (l + r) / 2;
            if(check(mid)) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};