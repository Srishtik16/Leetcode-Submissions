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
    map<TreeNode*, int> dp;
    map<int, int> cnt;
    void dfs(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        dp[root] = root -> val;
        dfs(root -> left);
        dfs(root -> right);
        dp[root] += root -> left ? dp[root -> left] : 0;
        dp[root] += root -> right ? dp[root -> right] : 0;
        cnt[dp[root]]++;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dp.clear();
        cnt.clear();
        dfs(root);
        int mx = 0;
        for(auto x: cnt) {
            if(x.second > mx) {
                mx = x.second;
            }
        }
        vector<int> ans;
        for(auto x: cnt) {
            if(x.second == mx) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};