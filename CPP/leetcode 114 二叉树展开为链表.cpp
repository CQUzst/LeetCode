/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    void flatten(TreeNode* root) {
        //递归，先用DFS找到左子树的最左节点，然后将该最左节点的父节点和右子树断开
        if(!root) return;
        flatten(root->left);
        flatten(root->right);
        if(!root->left) return;
        //将根节点与左右子树链接打断，根节点的右子树接到原左子树，新左子树置零，原左子树后面再接上原右子树
        TreeNode *temp=root->right;
        root->right=root->left;
        root->left=nullptr;
        while(root->right)//接上的可能是一段链表了，要循环到最尾部接上新右子树
            root=root->right;
        root->right=temp;
    }
};