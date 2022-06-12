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
    void dfs(TreeNode* root, vector<string> &ans, string path) {
        if(root -> left == NULL && root -> right == NULL) {
            // path += to_string(root -> val);
            ans.push_back(path + to_string(root -> val));
            return;
        }
        if(root -> left == NULL) {
            dfs(root -> right, ans, path + to_string(root -> val) + "->");
            return;
        }
        if(root -> right == NULL) {
            dfs(root -> left, ans, path + to_string(root -> val) + "->");
            return;
        }
        dfs(root -> right, ans, path + to_string(root -> val) + "->");
        dfs(root -> left, ans, path + to_string(root -> val) + "->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        if(root == NULL) {
            return ans;
        }
        dfs(root, ans, path);
        return ans;
    }
};