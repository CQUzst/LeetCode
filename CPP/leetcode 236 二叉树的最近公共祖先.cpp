/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const static auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root ==q) //如果存在p返回p，或者一直到底都没找到，返回空
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);//如果pq都在root的左子树，那么就递归root的左子树
        TreeNode* right = lowestCommonAncestor(root->right, p, q);//右子树同理
        if(left && right)
            return root;
        if (!left)
            return right;
        else
            return left;
    }
};