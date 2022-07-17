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
    map<TreeNode*, int> dp1, dp2;
    void dfs(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        dp1[root] = root -> val;
        dp2[root] = 1;
        if(root -> left) {
            dfs(root -> left);
            dp1[root] += dp1[root -> left];
            dp2[root] += dp2[root -> left];
        }
        if(root -> right) {
            dfs(root -> right);
            dp1[root] += dp1[root -> right];
            dp2[root] += dp2[root -> right];
        }
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dp1.clear();
        dp2.clear();
        dfs(root);
        for(auto x: dp1) {
            if(x.first -> val == x.second / dp2[x.first]) {
                ans++;
            }
        }
        return ans;
    }
};