// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         if(root){
//             res.push_back(root->val);
//             preorderTraversal(root->left);
//             preorderTraversal(root->right);
//         }
//         return res;
//     }
// private:
//     vector<int> res;
// };

// Binary Tree Preorder Traversal
// 前序遍历，先根后左右，先进先出，使用栈，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> s;
        if (root) //由跟节点开始进入while循环
            s.push(root);
        while (!s.empty()) {
            TreeNode *p = s.top();
            s.pop();
            result.push_back(p->val);
            if (p->right) 
                s.push(p->right);
            if (p->left) 
                s.push(p->left);
        }
        return result;
    }
};