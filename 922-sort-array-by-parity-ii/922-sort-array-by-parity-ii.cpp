class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd, even;
        for(auto &x: nums) {
            if(x & 1) {
                odd.push_back(x);
            }
            else {
                even.push_back(x);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                ans.push_back(even.back());
                even.pop_back();
            }
            else {
                ans.push_back(odd.back());
                odd.pop_back();
            }
        }
        return ans;
    }
};