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
    map<TreeNode*, bool> vis;
    TreeNode* start;
    TreeNode* end;
    string path;
    void dfs(TreeNode* root, TreeNode* parent, int s, int e) {
        if(root == NULL) {
            return;
        }
        if(root -> val == s) {
            start = root;
        }
        if(root -> val == e) {
            end = root;
        }
        par[root] = parent;
        dfs(root -> left, root, s, e);
        dfs(root -> right, root, s, e);
    }
    void dfs(TreeNode* root, TreeNode* e, string &p) {
        vis[root] = true;
        if(root == e) {
            path = p;
            return;
        }
        if(root -> left != NULL && !vis[root -> left]) {
            p.push_back('L');
            dfs(root -> left, e, p);
            p.pop_back();
        }
        if(root -> right != NULL && !vis[root -> right]) {
            p.push_back('R');
            dfs(root -> right, e, p);
            p.pop_back();
        }
        if(par[root] != NULL && !vis[par[root]]) {
            p.push_back('U');
            dfs(par[root], e, p);
            p.pop_back();
        }
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        par.clear();
        dfs(root, NULL, startValue, destValue);
        string p = "";
        path.clear();
        dfs(start, end, p);
        return path;
    }
};

// map<TreeNode*, TreeNode*> par
// dfs(node, NULL)
// par[node] = parent;