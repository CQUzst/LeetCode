/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//把问题拆分开：即便最后的最大路径没有经过根节点，它必然也有自己的“最高点”
//因此我们只要针对所有结点，求出：如果路径把这个节点作为“最高点”，路径最长可达多少？记为max。然后在max中求出最大值MAX即为所求结果
//找出左子树中以左孩子为起点的最大路径长度a，和右子树中以右孩子为起点的最大路径长度b。
//然后这个点的最长路径即为 Lmax = MAX(a+b+node.val, a+node.val, b+node.val, node.val)
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        maxPathSumCore(root);
        return MAX;
    }
    int maxPathSumCore(TreeNode *node) {
        if(!node) 
            return 0;
        
        //更新全局最大值
        int a = maxPathSumCore(node -> left);
        int b = maxPathSumCore(node -> right);
        if((a+b+node->val) > MAX) 
            MAX = (a+b+node->val);
        if((a+node->val) > MAX) 
            MAX = (a+node->val);
        if((b+node->val) > MAX) 
            MAX = (b+node->val);
        if(node->val > MAX) 
            MAX = node->val;
        
        //返回当前节点为起点的最大值
        int maxTemp = ((a + node->val) > node->val ? (a + node->val) : node->val);
        maxTemp = max(maxTemp,b + node->val);
        return maxTemp;
    }
private:
    int MAX= INT_MIN;
};