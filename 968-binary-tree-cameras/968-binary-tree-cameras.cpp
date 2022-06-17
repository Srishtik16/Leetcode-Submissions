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
    void dfs(TreeNode* node, TreeNode* par, set<TreeNode*> &s, int &ans) {
        if(node == NULL) {
            return;
        }
        dfs(node -> left, node, s, ans);
        dfs(node -> right, node, s, ans);
        if(par == NULL && s.find(node) == s.end() || s.find(node -> left) == s.end() || s.find(node -> right) == s.end()) {
            ans++;
            s.insert(node);
            s.insert(par);
            s.insert(node -> left);
            s.insert(node -> right);
        }
    }
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        set<TreeNode*> s;
        s.insert(NULL);
        dfs(root, NULL, s, ans);
        return ans;
    }
};