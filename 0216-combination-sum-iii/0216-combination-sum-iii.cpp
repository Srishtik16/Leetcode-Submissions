class Solution {
public:
    void backtrack(int k, int n, vector<vector<int>> &ans, vector<int> &res, int cnt, int digit) {
        if(cnt > k || digit > 10) {
            return;
        }
        if(cnt == k) {
            int sum = accumulate(res.begin(), res.end(), 0);
            sort(res.begin(), res.end());
            if(sum == n && find(ans.begin(), ans.end(), res) == ans.end()) {
                ans.push_back(res);
            }
            return;
        }
        res.push_back(digit);
        backtrack(k, n, ans, res, cnt + 1, digit + 1);
        res.pop_back();
        backtrack(k, n, ans, res, cnt, digit + 1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int cnt = 0, digit = 1;
        vector<int> res;
        vector<vector<int>> ans;
        backtrack(k, n, ans, res, cnt, digit);
        return ans;
    }
};