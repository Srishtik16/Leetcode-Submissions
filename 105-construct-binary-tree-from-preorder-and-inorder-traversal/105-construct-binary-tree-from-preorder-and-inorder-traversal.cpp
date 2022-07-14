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
    unordered_map<int, int> m;
TreeNode* dfs(vector<int> &post, int &postIndex, vector<int> &in, int currStart, int currEnd) {
	if(currStart > currEnd) {
		return NULL;
	}
	TreeNode* currNode = new TreeNode(post[postIndex]);
	postIndex++;
	if(currStart == currEnd) {
		return currNode;
	}
	int currIndex = m[currNode -> val];
	currNode -> left = dfs(post, postIndex, in, currStart, currIndex - 1);
	currNode -> right = dfs(post, postIndex, in, currIndex + 1, currEnd);
	return currNode;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        m.clear();
	for(int i = 0; i < preorder.size(); i++) {
		m[inorder[i]] = i;
	}
	int index = 0;
	return dfs(preorder, index, inorder, 0, preorder.size() - 1);
    }
};