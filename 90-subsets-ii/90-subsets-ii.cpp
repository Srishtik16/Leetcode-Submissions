class Solution {
public:
    void recurse(vector<vector<int>> &ans, vector<int> &aux, int index, vector<int> &a) {
        if(index == (int)a.size()) {
            vector<int> copy = aux;
            sort(copy.begin(), copy.end());
            if(find(ans.begin(), ans.end(), copy) == ans.end()) {
                ans.push_back(copy);
            }
            return;
        }
        aux.push_back(a[index]);
        recurse(ans, aux, index + 1, a);
        aux.pop_back();
        recurse(ans, aux, index + 1, a);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> aux;
        recurse(ans, aux, 0, nums);
        return ans;
    }
};