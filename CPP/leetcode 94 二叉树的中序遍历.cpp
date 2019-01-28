/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         Recursive(res,root);
//         return res;
//     }
// private:
//     void Recursive(vector<int> &res,TreeNode* root){
//         if(root==NULL) return;
//         else{
//             Recursive(res,root->left);
//             res.push_back(root->val);
//             Recursive(res,root->right);
//         }
//     }
// };

//左根右，先进后出，用栈
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (p ||!s.empty()) {
            if (p) //有根节点先压入，更新p为左子节点
            {
                s.push(p);
                p = p->left;
            } 
            else//到叶子节点了，取栈顶值，更新p为右节点
            {
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        return result;
    }
};