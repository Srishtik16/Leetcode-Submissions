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
    void inOrder(TreeNode* root, vector<int> &ans) {
        if(root == NULL) {
            ans.push_back(INT_MIN);
            return;
        }
        inOrder(root -> left, ans);
        inOrder(root -> right, ans);
        ans.push_back(root -> val);
    }
    void postOrder(TreeNode* root, vector<int> &ans) {
        if(root == NULL) {
            ans.push_back(INT_MIN);
            return;
        }
        postOrder(root -> left, ans);
        postOrder(root -> right, ans);
        ans.push_back(root -> val);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> p1, p2, p3, p4, p5, p6;
        preOrder(p, p1);
        inOrder(p, p2);
        postOrder(p, p3);
        preOrder(q, p4);
        inOrder(q, p5);
        postOrder(q, p6);
        return p1 == p4 && p2 == p5 && p3 == p6;
    }
};