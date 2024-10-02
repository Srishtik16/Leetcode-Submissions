class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums = arr;
        sort(nums.begin(), nums.end());
        map<int, int> m;
        int index = 1;
        for(auto x: nums) {
            if(m.find(x) == m.end()) {
                m[x] = index;
                index++;
                continue;
            }
        }
        for(auto &x: arr) {
            x = m[x];
        }
        return arr;
    }
};