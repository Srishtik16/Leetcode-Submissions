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
    void dfs(TreeNode* root, map<int, int> &path, int &ans) {
        if(root -> left == NULL && root -> right == NULL) {
            path[root -> val]++;
            int cnt = 0;
            for(auto x: path) {
                cnt += x.second & 1;
            }
            ans += cnt <= 1;
            path[root -> val]--;
            if(path[root -> val] == 0) {
                path.erase(root -> val);
            }
            return;
        }
        path[root -> val]++;
        if(root -> left != NULL) {
            dfs(root -> left, path, ans);
        }
        if(root -> right != NULL) {
            dfs(root -> right, path, ans);
        }
        path[root -> val]--;
        if(path[root -> val] == 0) {
            path.erase(root -> val);
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        map<int, int> path;
        dfs(root, path, ans);
        return ans;
    }
};