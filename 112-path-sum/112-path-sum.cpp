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
    bool ok = false;
    void dfs(TreeNode* root, int sum, int add = 0) {
        if(root == NULL) {
            return;
        }
        add += root -> val;
        if(sum == add && root -> left == NULL && root -> right == NULL) {
            ok = true;
            return;
        }
        dfs(root -> left, sum, add);
        dfs(root -> right, sum, add);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        ok = false;
        dfs(root, sum);
        return ok;
    }
};