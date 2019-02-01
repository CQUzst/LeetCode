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
private:
    TreeNode *recursion(vector<int>& inorder, vector<int>& postorder,int from,int to,int curRootIndex){
        if(from>to) return nullptr;
        int index=find(inorder.begin()+from,inorder.begin()+to,postorder[curRootIndex])-inorder.begin();
        TreeNode *root=new TreeNode(postorder[curRootIndex]);
        root->left=recursion(inorder,postorder,from,index-1,curRootIndex-1-(to-index));
        root->right=recursion(inorder,postorder,index+1,to,curRootIndex-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return recursion(inorder,postorder,0,inorder.size()-1,postorder.size()-1);
    }
};
