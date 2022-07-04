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
    map<int, vector<int>> levels;
    int dfs(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int lh = dfs(root -> left);
        int rh = dfs(root -> right);
        int height = max(lh, rh) + 1;
        levels[height].push_back(root -> val);
        return height;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        levels.clear();
        dfs(root);
        vector<vector<int>> ans;
        for(auto x: levels) {
            ans.push_back(x.second);
        }
        return ans;
    }
};