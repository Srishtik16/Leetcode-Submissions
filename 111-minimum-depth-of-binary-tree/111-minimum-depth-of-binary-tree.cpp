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
    void dfs(TreeNode* root, int &ans, int depth) {
        if(root -> left == NULL && root -> right == NULL) {
            ans = min(ans, depth + 1);
            return;
        }
        if(root -> left != NULL) {
            dfs(root -> left, ans, depth + 1);
        }
        if(root -> right != NULL) {
            dfs(root -> right, ans, depth + 1);
        }
    }
    int minDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int ans = INT_MAX;
        dfs(root, ans, 0);
        return ans;
    }
};