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
    map<TreeNode*, TreeNode*> par;
    TreeNode* begin;
    void dfs(TreeNode* node, int start) {
        if(node == NULL) {
            return;
        }
        if(node -> val == start) {
            begin = node;
        }
        if(node -> left != NULL) {
            par[node -> left] = node;
        }
        dfs(node -> left, start);
        if(node -> right != NULL) {
            par[node -> right] = node;
        }
        dfs(node -> right, start);
    }
    int amountOfTime(TreeNode* root, int start) {
        par.clear();
        TreeNode* node = root;
        begin = root;
        dfs(node, start);
        queue<TreeNode*> q;
        map<TreeNode*, bool> vis;
        int minutes = -1;
        q.push(begin);
        vis[begin] = true;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                auto u = q.front();
                q.pop();
                if(par.find(u) != par.end() && par[u] != NULL && !vis[par[u]]) {
                    vis[par[u]] = true;
                    q.push(par[u]);
                }
                if(u -> left != NULL && !vis[u -> left]) {
                    vis[u -> left] = true;
                    q.push(u -> left);
                }
                if(u -> right != NULL && !vis[u -> right]) {
                    vis[u -> right] = true;
                    q.push(u -> right);
                }
            }
            minutes++;
        }
        return minutes;
    }
};