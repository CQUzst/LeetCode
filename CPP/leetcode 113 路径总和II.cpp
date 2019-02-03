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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> road;
        dfs(root,sum,road,res);
        return res;
    }
private:
    void dfs(TreeNode* root,int sum,vector<int> &road,vector<vector<int>> &res){
        if(!root)
            return;
        road.push_back(root->val);//road存储路过的每个节点的路径
        if(root->val==sum&&root->left==nullptr&&root->right==nullptr)
            res.push_back(road);
        dfs(root->right,sum-root->val,road,res);
        dfs(root->left,sum-root->val,road,res);    
        road.pop_back();//递归后要保存现场（进入递归前的状态）
    }
};