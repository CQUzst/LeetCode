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
    bool isSymmetric(TreeNode* root) {
        if(!root) 
            return true;   //空树是对称的  
        return symmetric(root->left,root->right);  
    }  
private:  
   bool symmetric(TreeNode *p,TreeNode *q)       /*判断两棵树是否对称*/  
    {     
       if(!p && !q) return true;       //都是空  
       if(!p || !q) return false;      //只有一个空  
       //树p和树q对称的条件：p和q的值相同，并且p的左子树与q的右子树对称，p的右子树与q的左子树对称
       return (p->val==q->val)&&symmetric(p->left,q->right) && symmetric(p->right,q->left);     
         
    }
};