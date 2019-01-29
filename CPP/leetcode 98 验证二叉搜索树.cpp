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
    bool isValidBST(TreeNode* root){
        vector<int> res;
        res.clear();
        Inorder(root, res);
        if (res.empty() || res.size() == 1)
            return true;
        for (int i = 0; i < res.size() - 1; i++){
            if (res[i] >= res[i+1])
                return false;
        }
        return true;
    }
    //中序遍历，左中右，后面的比前面大
    void Inorder(TreeNode *root, vector<int> &res)
    {
        if (!root)
           return;
        Inorder(root->left, res);
        res.push_back(root->val);
        Inorder(root->right, res);
    }
};