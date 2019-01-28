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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;//存放结果返回值
        vector<int> levelNode;//每一层的节点
        queue<TreeNode *> Q;
        
        if(root) 
            Q.push(root);
        else
            return res;
        int nextCount=0;         //下一层元素的个数
        int currentLevelCount=1;   //当前层元素个数，初始为第一层
        while( !Q.empty())
        {
            TreeNode *cur=Q.front();
            levelNode.push_back(cur->val);//存入当前层最前面的节点值
            Q.pop();//删除当前节点
            currentLevelCount--;//当前层的节点数-1
            if(cur->left)
            {
                Q.push(cur->left);
                nextCount++;
            }
            if(cur->right)
            {
                Q.push(cur->right);
                nextCount++;
            }
            if(currentLevelCount==0)//当前层空了，下一层还有
            {
                res.push_back(levelNode);//把一层节点push_back
                currentLevelCount=nextCount;//更新下一层节点数为当前节点数
                nextCount=0;
                levelNode.clear();  //清空levelNode，为下一层存入做准备
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};