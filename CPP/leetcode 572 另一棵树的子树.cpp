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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s&&!t) return true;
        if(!s||!t) return false;
        if(s->val == t->val && isSame(s,t)) return true;
        return isSubtree(s->left , t) || isSubtree(s->right , t);
    }
    bool isSame(TreeNode* s,TreeNode* t){
        if(!s&&!t) return true;
        if(!s||!t) return false;
        if(s->val != t->val) return false;
        return isSame(s->left , t->left) && isSame(s->right , t->right);
    }
};
