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
    int mxd;
    void dfs(TreeNode* root, int depth) {
        if(root == NULL) {
            return;
        }
        mxd = max(mxd, depth);
        dfs(root -> left, depth + 1);
        dfs(root -> right, depth + 1);
    }
    void dfs(TreeNode* root, int depth, int &sum) {
        if(root == NULL) {
            return;
        }
        if(mxd == depth) {
            sum += root -> val;
        }
        dfs(root -> left, depth + 1, sum);
        dfs(root -> right, depth + 1, sum);
    }
    int deepestLeavesSum(TreeNode* root) {
        TreeNode* copy = root;
        dfs(copy, 0);
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};