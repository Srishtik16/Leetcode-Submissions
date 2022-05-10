class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &aux, int k, int n, int cnt, int digit) {
        if(cnt > k) {
            return;
        }
        if(digit > 10) {
            return;
        }
        if(cnt == k) {
            if(!aux.empty() && accumulate(aux.begin(), aux.end(), 0) == n) {
                ans.push_back(aux);
            }
            return;
        }
        aux.push_back(digit);
        backtrack(ans, aux, k, n, cnt + 1, digit + 1);
        aux.pop_back();
        backtrack(ans, aux, k, n, cnt, digit + 1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> aux;
        backtrack(ans, aux, k, n, 0, 1);
        return ans;
    }
};