class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }
        for(auto x: m) {
            int l = x.second.size();
            for(int i = 0; i < l - 1; i++) {
                if(abs(x.second[i] - x.second[i + 1]) <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};