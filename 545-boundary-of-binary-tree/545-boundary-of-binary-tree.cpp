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
    vector<int> getLeftBoundary(TreeNode* root) {
        root = root -> left;
        vector<int> lb;
        while(root != NULL) {
            if(root -> left != NULL || root -> right != NULL) {
                lb.push_back(root -> val);
            }
            root = root -> left ? root -> left : root -> right;
        }
        return lb;
    }
    vector<int> getRightBoundary(TreeNode* root) {
        root = root -> right;
        vector<int> rb;
        while(root != NULL) {
            if(root -> left != NULL || root -> right != NULL) {
                rb.push_back(root -> val);
            }
            root = root -> right ? root -> right : root -> left;
        }
        reverse(rb.begin(), rb.end());
        return rb;
    }
    void dfs(TreeNode* root, vector<int> &lv) {
        if(root == NULL) {
            return;
        }
        if(root -> left == NULL && root -> right == NULL) {
            lv.push_back(root -> val);
        }
        dfs(root -> left, lv);
        dfs(root -> right, lv);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        if(root -> left == NULL && root -> right == NULL) {
            return {root -> val};
        }
        vector<int> ans;
        TreeNode* copy = root;
        ans.push_back(root -> val);
        vector<int> lb = getLeftBoundary(root);
        root = copy;
        vector<int> rb = getRightBoundary(root);
        for(auto x: lb) {
            ans.push_back(x);
        }
        vector<int> lv;
        root = copy;
        dfs(root, lv);
        for(auto x: lv) {
            ans.push_back(x);
        }
        for(auto x: rb) {
            ans.push_back(x);
        }
        return ans;
    }
};