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
    void dfs(TreeNode* root, int &count) {
        if(root == NULL) {
            return;
        }
        count++;
        dfs(root -> left, count);
        dfs(root -> right, count);
    }
    bool check(TreeNode* root, int index, int n) {
        if(root == NULL) {
            return true;
        }
        if(index >= n) {
            return false;
        }
        return check(root -> left, 2 * index + 1, n) && check(root -> right, 2 * index + 2, n);
    }
    bool isCompleteTree(TreeNode* root) {
        int count = 0;
        TreeNode* node = root;
        dfs(root, count);
        return check(node, 0, count);
    }
};