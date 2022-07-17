/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int dep, int hor, map<int, vector<pair<int, int>>> &m) {
        if(root == NULL) {
            return;
        }
        m[hor].push_back({dep, root -> val});
        dfs(root -> left, dep + 1, hor - 1, m);
        dfs(root -> right, dep + 1, hor + 1, m);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> m;
        dfs(root, 0, 0, m);
        for(auto &x: m) {
            sort(x.second.begin(), x.second.end());
        }
        vector<vector<int>> ans;
        for(auto x: m) {
            vector<int> res;
            for(auto y: x.second) {
                res.push_back(y.second);
            }
            ans.push_back(res);
        }
        return ans;
    }
};