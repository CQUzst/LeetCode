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
//     int sumNumbers(TreeNode *root) {
//         int res=0;
//         return dfs(root, res);
//     }
// private:
//     int dfs(TreeNode *root, int res) {
//         if (root == nullptr) 
//             return 0;
//         if (root->left == nullptr && root->right == nullptr)//到叶子节点将之前路径的值*10加上叶子节点值
//             return res * 10 + root->val;
//         return dfs(root->left, res * 10 + root->val) +dfs(root->right, res * 10 + root->val);
//     }
// };

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res=0;
        oneRoad(root,0,res);
        return res;
    }
    void oneRoad(TreeNode* root,int sum,int &res) {
        if(root==nullptr) 
            return;
        sum=sum*10+root->val;
        oneRoad(root->left,sum,res);
        oneRoad(root->right,sum,res);
        if(root->left==nullptr && root->right==nullptr)//到叶子节点添加到res中
            res+=sum;
    }
};