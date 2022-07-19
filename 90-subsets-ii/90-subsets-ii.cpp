class Solution {
    map<vector<int>, bool> m;
public:
    void subsets(int index, vector<vector<int>> &ans, vector<int> &curr, vector<int> &a) {
        if(index == (int)a.size()) {
            if(m.find(curr) == m.end()) {
                ans.push_back(curr);
                m[curr] = 1;
            }
            return;
        }
        curr.push_back(a[index]);
        subsets(index + 1, ans, curr, a);
        curr.pop_back();
        subsets(index + 1, ans, curr, a);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        m.clear();
        vector<vector<int>> ans;
        vector<int> curr;
        subsets(0, ans, curr, nums);
        return ans;
    }
};