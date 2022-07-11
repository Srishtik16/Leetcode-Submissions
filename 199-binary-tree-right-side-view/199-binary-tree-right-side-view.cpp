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
    void dfs(TreeNode* root, int level) {
        if(root == NULL) {
            return;
        }
        levels[level].push_back(root -> val);
        dfs(root -> left, level + 1);
        dfs(root -> right, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        levels.clear();
        dfs(root, 0);
        vector<int> ans;
        for(auto x: levels) {
            ans.push_back(x.second.back());
        }
        return ans;
    }
};