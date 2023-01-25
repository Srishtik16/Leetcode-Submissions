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
    void dfs(TreeNode* root, int sum, vector<int> &ans, vector<vector<int>> &res) {
        if(root == NULL) {
            return;
        }
        ans.push_back(root -> val);
        if(root -> left == NULL && root -> right == NULL) {
            int s = 0;
            for(auto x: ans) {
                s += x;
            }
            if(s == sum) {
                res.push_back(ans);
            }
        }
        dfs(root -> left, sum, ans, res);
        dfs(root -> right, sum, ans, res);
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        vector<vector<int>> res;
        if(root == NULL) {
            return res;
        }
        dfs(root, targetSum, ans, res);
        return res;
    }
};