class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        multiset<pair<int, int>> ms;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            ms.insert({nums[i], i});
        }
        while(k--) {
            auto val = *ms.begin();
            ms.erase(ms.begin());
            val.first *= multiplier;
            ms.insert(val);
        }
        vector<int> ans(n);
        for(auto x: ms) {
            ans[x.second] = x.first;
        }
        return ans;
    }
};