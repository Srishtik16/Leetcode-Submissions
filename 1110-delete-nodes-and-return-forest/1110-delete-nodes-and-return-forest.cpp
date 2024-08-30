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
    vector<TreeNode*> ans;
    unordered_set<int> s;
    TreeNode* dfs(TreeNode* node) {
        if(node == NULL) {
            return NULL;
        }
        node -> left = dfs(node -> left);
        node -> right = dfs(node -> right);
        if(s.find(node -> val) != s.end()) {
            if(node -> left) {
                ans.push_back(node -> left);
            }
            if(node -> right) {
                ans.push_back(node -> right);
            }
            delete node;
            return NULL;
        }
        return node;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        s = unordered_set<int>(to_delete.begin(), to_delete.end());
        ans.clear();
        root = dfs(root);
        if(root) {
            ans.push_back(root);
        }
        return ans;
    }
};