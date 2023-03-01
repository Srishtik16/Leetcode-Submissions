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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0, mxSum = INT_MIN;
        int level = 1;
        while(!q.empty()) {
            int qs = q.size();
            int sum = 0;
            while(qs--) {
                auto u = q.front();
                q.pop();
                sum += u -> val;
                if(u -> left != NULL) {
                    q.push(u -> left);
                }
                if(u -> right != NULL) {
                    q.push(u -> right);
                }
            }
            if(mxSum < sum) {
                ans = level;
                mxSum = sum;
            }
            level++;
        }
        return ans;
    }
};