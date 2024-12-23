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
    int minimumOperations(TreeNode* root) {
        auto countSort = [&](vector<int> &a) {
            vector<int> copy = a;
            sort(copy.begin(), copy.end());
            map<int, int> m, vis;
            int idx = 0;
            for(auto x: copy) {
                m[x] = idx++;
                vis[x] = false;
            }
            int count = 0;
            for(auto x: a) {
                int val = x;
                int swaps = -1;
                while(!vis[val]) {
                    vis[val] = true;
                    val = a[m[val]];
                    swaps++;
                }
                count += swaps == -1 ? 0 : swaps;
            }
            return count;
        };
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()) {
            int qs = q.size();
            vector<int> nodes;
            while(qs--) {
                auto node = q.front();
                q.pop();
                nodes.push_back(node -> val);
                if(node -> left) {
                    q.push(node -> left);
                }
                if(node -> right) {
                    q.push(node -> right);
                }
            }
            ans += countSort(nodes);
        }
        return ans;
    }
};