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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) {
            return vector<vector<int>>();
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        int levels = 0;
        while(!q.empty()) {
            int qs = q.size();
            vector<int> a;
            while(qs--) {
                auto u = q.front();
                q.pop();
                a.push_back(u -> val);
                if(u -> left != NULL) {
                    q.push(u -> left);
                }
                if(u -> right != NULL) {
                    q.push(u -> right);
                }
            }
            levels ^= 1;
            if(levels % 2 == 0) {
                reverse(a.begin(), a.end());
            }
            ans.push_back(a);
        }
        return ans;
    }
};