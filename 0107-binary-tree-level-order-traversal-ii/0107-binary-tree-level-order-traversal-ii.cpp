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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int qs = q.size();
            vector<int> levels;
            while(qs--) {
                auto u = q.front();
                q.pop();
                levels.push_back(u -> val);
                if(u -> left != NULL) {
                    q.push(u -> left);
                }
                if(u -> right != NULL) {
                    q.push(u -> right);
                }
            }
            ans.push_back(levels);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};