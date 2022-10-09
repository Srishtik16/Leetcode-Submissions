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
    map<int, int> m;
    void dfs(TreeNode* root, int k, bool &ok) {
        if(root == NULL) {
            return;
        }
        m[root -> val]++;
        dfs(root -> left, k, ok);
        if(k - root -> val != root -> val && m[k - root -> val] == 1) {
            ok = true;
        }
        else if(k - root -> val == root -> val && m[k - root -> val] > 1) {
            ok = true;
        }
        dfs(root -> right, k, ok);
        if(k - root -> val != root -> val && m[k - root -> val] == 1) {
            ok = true;
        }
        else if(k - root -> val == root -> val && m[k - root -> val] > 1) {
            ok = true;
        }
    }
    bool findTarget(TreeNode* root, int k) {
        bool ok = false;
        dfs(root, k, ok);
        return ok;
    }
};