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
    void dfs(TreeNode* root, vector<int> &a) {
        if(root == NULL) {
            a.push_back(INT_MIN);
            return;
        }
        a.push_back(root -> val);
        dfs(root -> left, a);
        dfs(root -> right, a);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> x, y;
        dfs(p, x);
        dfs(q, y);
        return x == y;
    }
};