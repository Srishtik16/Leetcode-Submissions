class Solution {
public:
    int longestWPI(vector<int>& hours) {
        for(auto &x: hours) {
            x = x > 8 ? 1 : -1;
        }
        int n = hours.size();
        map<int, int> m;
        int sum = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            sum += hours[i];
            if(sum > 0) {
                ans = max(ans, i + 1);
            }
            else {
                if(m.find(sum - 1) != m.end()) {
                    ans = max(ans, i - m[sum - 1]);
                }
            }
            if(m.find(sum) == m.end()) {
                m[sum] = i;
            }
        }
        return ans;
    }
};