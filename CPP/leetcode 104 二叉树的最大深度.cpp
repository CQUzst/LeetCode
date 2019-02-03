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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
        // int left = maxDepth(root -> left) + 1;
        // int right = maxDepth(root -> right) + 1;
        // return left > right ? left : right;
    }
};