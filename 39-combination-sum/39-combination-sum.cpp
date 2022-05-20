class Solution {
public:
    void recurse(vector<vector<int>> &ans, vector<int> &aux, int sum, int target, int index, vector<int> &a) {
        if(index >= (int)a.size()) {
            return;
        }
        if(sum > target) {
            return;
        }
        if(sum == target) {
            vector<int> copy = aux;
            sort(copy.begin(), copy.end());
            if(find(ans.begin(), ans.end(), copy) == ans.end()) {
                ans.push_back(aux);
            }
            return;
        }
        sum += a[index];
        aux.push_back(a[index]);
        recurse(ans, aux, sum, target, index, a);
        sum -= a[index];
        aux.pop_back();
        recurse(ans, aux, sum, target, index + 1, a);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> aux;
        recurse(ans, aux, 0, target, 0, candidates);
        return ans;
    }
};