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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        map<TreeNode*, int> vis;
        vis[root] = true;
        q.push(root);
        ans.push_back(root -> val);
        while(!q.empty()) {
            int qs = q.size();
            int res = INT_MIN;
            while(qs--) {
                auto u = q.front();
                q.pop();
                if(u -> left != NULL && !vis[u -> left]) {
                    vis[u -> left] = true;
                    res = max(res, u -> left -> val);
                    q.push(u -> left);
                }
                if(u -> right != NULL && !vis[u -> right]) {
                    vis[u -> right] = true;
                    res = max(res, u -> right -> val);
                    q.push(u -> right);
                }
            }
            ans.push_back(res);
        }
        ans.pop_back();
        return ans;
    }
};