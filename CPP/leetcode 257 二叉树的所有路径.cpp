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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root==nullptr)
            return res;
        string ans;
        recursion(root,res,ans);//简单的递归即可
        return res;
    }
private:
    void recursion(TreeNode* root,vector<string> &res,string ans){
        if(root->left==nullptr&&root->right==nullptr)//如果是叶子，将最后一个数加入ans，push到res
        {
            ans+=to_string(root->val);
            res.push_back(ans);
            return;
        }
        ans+=to_string(root->val)+"->";
        if(root->left!=nullptr)
            recursion(root->left,res,ans);
        if(root->right!=nullptr)
            recursion(root->right,res,ans);
        return;
    }
};
