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
    map<string, int> m;
    string dfs(TreeNode* root) {
        if(root == NULL) {
            return "";
        }
        string subtree = "(" + dfs(root -> left) + ")" + to_string(root -> val) + "(" + dfs(root -> right) + ")";
        m[subtree]++;
        if(m[subtree] == 2) {
            ans.push_back(root);
        }
        return subtree;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        ans.clear();
        m.clear();
        dfs(root);
        return ans;
    }
};