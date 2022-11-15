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
    int getLeft(TreeNode* root) {
        int cnt = 1;
        while(root != NULL) {
            root = root -> left;
            cnt++;
        }
        return cnt;
    }
    int getRight(TreeNode* root) {
        int cnt = 1;
        while(root != NULL) {
            root = root -> right;
            cnt++;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }   
        int lh = getLeft(root -> left);
        int rh = getRight(root -> right);
        if(lh == rh) {
            return (1LL << lh) - 1;
        }
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};