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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        // 这里直接使用函数返回值进行减法，免去存放在整形变量中可以减少空间开销
        if(abs(deep(root->left) - deep(root->right)) > 1)
            return false;
        else return isBalanced(root->left)&&isBalanced(root->right);
    }
    int deep(TreeNode *root){
        if(!root) return 0;
        return max(deep(root->left),deep(root->right))+1;
    }
};