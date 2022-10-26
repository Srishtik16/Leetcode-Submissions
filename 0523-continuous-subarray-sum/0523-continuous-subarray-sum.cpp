class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, ans = 0;
        unordered_map<int, vector<int>> m;
        m[sum].push_back(-1);
        for(int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % k;
            m[sum].push_back(i);
        }
        for(auto x: m) {
            if(abs(x.second.back() - x.second[0]) > 1) {
                return true;
            }
        }
        return false;
    }
};