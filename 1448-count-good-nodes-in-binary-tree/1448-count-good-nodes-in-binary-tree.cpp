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
    int good;
    void dfs(TreeNode* root, int ans) {
        if(root == NULL) {
            return;
        }
        if(ans <= root -> val) {
            good++;
            ans = max(ans, root -> val);
        }
        dfs(root -> left, ans);
        dfs(root -> right, ans);
    }
    int goodNodes(TreeNode* root) {
        good = 0;
        dfs(root, INT_MIN);
        return good;
    }
};