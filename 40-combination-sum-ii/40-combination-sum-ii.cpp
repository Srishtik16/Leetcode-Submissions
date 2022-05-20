class Solution {
public:
    void recurse(vector<vector<int>> &ans, vector<int> &aux, int target, int index, vector<int> &a) {
        if(target == 0) {
            ans.push_back(aux);
            return;
        }
        for(int i = index; i < (int)a.size(); i++) {
            if(i > index && a[i] == a[i - 1]) {
                continue;
            }
            if(a[i] > target) {
                break;
            }
            aux.push_back(a[i]);
            recurse(ans, aux, target - a[i], i + 1, a);
            aux.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> aux;
        sort(candidates.begin(), candidates.end());
        recurse(ans, aux, target, 0, candidates);
        return ans;
    }
};