class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        set<pair<int, int>> s;
        for(int i = 0; i < n; i++) {
            s.insert({nums[i], i});
        }
        vector<long long> ans;
        for(auto q: queries) {
            int index = q[0], k = q[1];
            if(s.find({nums[index], index}) != s.end()) {
                s.erase({nums[index], index});
                sum -= nums[index];
            }
            while(k-- && !s.empty()) {
                auto val = *s.begin();
                sum -= val.first;
                s.erase(val);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};