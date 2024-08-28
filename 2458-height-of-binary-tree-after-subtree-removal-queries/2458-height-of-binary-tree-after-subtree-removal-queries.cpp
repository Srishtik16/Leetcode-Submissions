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
    map<int, int> depth, level;
    map<int, pair<int, int>> maxes;
    int dfs(TreeNode* root, int lvl) {
        if(root == NULL) {
            return 0;
        }
        level[root -> val] = lvl;
        int l = dfs(root -> left, lvl + 1);
        int r = dfs(root -> right, lvl + 1);
        depth[root -> val] = 1 + max(l, r);
        if(maxes[lvl].first < depth[root -> val]) {
            maxes[lvl].second = maxes[lvl].first;
            maxes[lvl].first = depth[root -> val];
        }
        else if(maxes[lvl].second < depth[root -> val]) {
            maxes[lvl].second = depth[root -> val];
        }
        return depth[root -> val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        depth.clear();
        level.clear();
        maxes.clear();
        dfs(root, 0);
        vector<int> ans;
        for(auto x: queries) {
            ans.push_back(level[x] + (maxes[level[x]].first == depth[x] ? maxes[level[x]].second : maxes[level[x]].first) - 1);
        }
        return ans;
    }
};

// dp[i] = {largest and 2nd largest depth from node x}
// if I remove node x, and depth of x = largest depth from parent - 1, then we do 2nd max, else max