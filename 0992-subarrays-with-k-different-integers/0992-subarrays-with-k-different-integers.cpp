class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // count subarrays with atmost k distinct -> s1
        // count subarrays with atmost k - 1 distinct -> s2
        // ans = s1 - s2
        // use 2 pointers to expand contract window
        int n = nums.size();
        auto count = [&](int distinct) {
            int l = 0, r = 0;
            map<int, int> vis;
            map<int, int> m;
            int cnt = 0;
            while(l <= r && r < n) {
                m[nums[r]]++;
                while(m.size() > distinct) {
                    m[nums[l]]--;
                    if(m[nums[l]] == 0) {
                        m.erase(nums[l]);
                    }
                    l++;
                }
                cnt += r - l + 1;
                r++;
            }
            return cnt;
        };
        return count(k) - count(k - 1);
    }
};