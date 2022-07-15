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
    void dfs(TreeNode* root, int val) {
        if(root -> val < val) {
            if(root -> right != NULL) {
                dfs(root -> right, val);
            }
            else {
                root -> right = new TreeNode(val);
                return;
            }
        }
        else {
            if(root -> left != NULL) {
                dfs(root -> left, val);
            }
            else {
                root -> left = new TreeNode(val);
                return;
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            root = new TreeNode(val);
            return root;
        }
        TreeNode* copy = root;
        dfs(root, val);
        return copy;
    }
};