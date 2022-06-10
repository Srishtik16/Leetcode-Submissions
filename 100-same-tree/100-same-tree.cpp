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
    void preOrder(TreeNode* root, vector<int> &ans) {
        if(root == NULL) {
            ans.push_back(INT_MIN);
            return;
        }
        preOrder(root -> left, ans);
        preOrder(root -> right, ans);
        ans.push_back(root -> val);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> p1, p4;
        preOrder(p, p1);
        preOrder(q, p4);
        return p1 == p4;
    }
};