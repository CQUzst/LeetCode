/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr)
            return false;
        if(root->left==nullptr&&root->right==nullptr&&root->val==sum)
            return true;
        //递归,每下降一层减去当前节点值，直到叶子节点且剩余值等于叶子节点值
        return (hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val));
    }
};