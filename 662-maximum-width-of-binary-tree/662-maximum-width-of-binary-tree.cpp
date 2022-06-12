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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()) {
            vector<long long> ids;
            int qs = q.size();
            long long mn = q.front().second;
            while(qs--) {
                TreeNode* node = q.front().first;
                long long id = q.front().second;
                id -= mn;
                q.pop();
                ids.push_back(id);
                if(node -> left != NULL) {
                    q.push({node -> left, 2 * id + 1});
                }
                if(node -> right != NULL) {
                    q.push({node -> right, 2 * id + 2});
                }
            }
            ans = max(ans, (int)abs(ids.back() - ids[0]) + 1);
        }
        return ans;
    }
};