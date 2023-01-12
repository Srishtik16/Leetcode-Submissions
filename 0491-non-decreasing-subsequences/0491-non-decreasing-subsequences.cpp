class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        map<vector<int>, bool> m;
        for(int mask = 0; mask < (1LL << n); mask++) {
            vector<int> a;
            for(int i = 0; i < n; i++) {
                if((1LL << i) & mask) {
                    a.push_back(nums[i]);
                }
            }
            if(is_sorted(a.begin(), a.end()) && a.size() >= 2 && m.find(a) == m.end()) {
                ans.push_back(a);
                m[a] = true;
            }
        }
        return ans;
    }
};