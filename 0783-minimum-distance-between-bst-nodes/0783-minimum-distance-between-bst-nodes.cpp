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
    vector<int> nodes;
    void dfs(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        nodes.push_back(root -> val);
        dfs(root -> left);
        dfs(root -> right);
    }
    int minDiffInBST(TreeNode* root) {
        nodes.clear();
        dfs(root);
        sort(nodes.begin(), nodes.end());
        int ans = INT_MAX;
        for(int i = 0; i < (int)nodes.size() - 1; i++) {
            ans = min(ans, abs(nodes[i] - nodes[i + 1]));
        }
        return ans;
    }
};