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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode*>{};
        return backonTrace(1,n);
    }
private:
    vector<TreeNode*> backonTrace(int begin, int end){
        vector<TreeNode*> res;
        if(begin > end){
            res.push_back(nullptr);
            return res;
        }
        // 要生成根节点为i (1 <= i <= n)的所有BST
        // 那么首先需要生成范围为1到i-1的所有BST作为左子树，以及范围为i+1到n的所有BST作为右子树
        // 然后两两组合就可以形成根节点为k的所有BST
        for(int i = begin; i <= end; ++i){
            vector<TreeNode*> left = backonTrace(begin, i-1);
            vector<TreeNode*> right = backonTrace(i+1, end);
            //当前i作为根结点
            for(auto l : left){
                for(auto r : right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);//以i为根节点有left*right种情况
                }
            }
        }
        return res;
    }
};