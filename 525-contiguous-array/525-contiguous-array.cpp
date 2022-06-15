class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        m[0] = -1;
        int cnt = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            cnt += (nums[i] == 1 ? 1 : -1);
            if(m.find(cnt) != m.end()) {
                ans = max(ans, i - m[cnt]);
            }
            else {
                m[cnt] = i;
            }
        }
        return ans;
    }
};