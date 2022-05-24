class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> m;
        for(int i = 1; i <= 1000; i++) {
            for(auto x: nums) {
                if(find(x.begin(), x.end(), i) != x.end()) {
                    m[i]++;
                }
            }
        }
        vector<int> ans;
        for(int i = 1; i <= 1000; i++) {
            if(m[i] == nums.size()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};