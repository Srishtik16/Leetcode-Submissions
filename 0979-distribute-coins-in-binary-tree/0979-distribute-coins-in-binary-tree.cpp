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
    int moves;
    int dfs(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int left = dfs(root -> left);
        int right = dfs(root -> right);
        moves += abs(left) + abs(right);
        return root -> val + left + right - 1;
    }
    int distributeCoins(TreeNode* root) {
        // a node can give coins or take (+ve or -ve coins)
        // start from leaves and send to parent
        // moves = abs(left) + abs(right) (Give or take)
        moves = 0;
        dfs(root);
        return moves;
    }
};