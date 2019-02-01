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
//     TreeNode* myfun(int pre_begin,int pre_end,int inorder_begin,int inorder_end,
//                     vector<int>& preorder,vector<int>& inorder)
//     {
       
//           TreeNode* root=new TreeNode(preorder[pre_begin]);//前序遍历的第一个就是根节点
//           int left_end=0;
//           int i=inorder_begin;
//           for(;i<=inorder_end;i++)
//           {
//               if(inorder[i]==preorder[pre_begin])//在中序遍历中找到前序遍历的第一个，也就是根节点
//               {
//                   left_end=pre_begin+i-inorder_begin;
//                   break;
//               }
//           }
        
//           if(left_end>pre_begin&&i-1>=inorder_begin)
//             root->left=myfun(pre_begin+1,left_end,inorder_begin,i-1,preorder,inorder);
//             else
//                 root->left=nullptr;
//             int right_begin=left_end+1;
//             if(right_begin<=pre_end&&i+1<=inorder_end)
//                 root->right=myfun(right_begin,pre_end,i+1,inorder_end,preorder,inorder);
//             else
//                 root->right=nullptr;
//               return root;   
//     }
    
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
//     {
//         int length=preorder.size();
//         if(length==0)
//            return nullptr;        
//         return myfun(0,length-1,0,length-1,preorder,inorder);
//     }
// };
class Solution 
{
private:
    TreeNode* recursion(vector<int>& preorder, vector<int>& inorder, int from, int to, int curRootIndex)
    {
        if(from > to) 
            return NULL;
        //从中序遍历中找到和前序遍历的第一个相同的点,也就是根节点,index是中序遍历中根节点的下标
        int index = find(inorder.begin()+from,inorder.begin()+to,preorder[curRootIndex]) - inorder.begin();
        TreeNode* root = new TreeNode(preorder[curRootIndex]);
        //此时左子树范围就是中序遍历的index的左边,右子树范围就是index右边
        //此时前序序列中左子树的起始点就是母左子树的下一个,右子树是母左子树的下一个加上整个左子树范围(中序中的index-from)
        root->left = recursion(preorder,inorder,from,index-1,curRootIndex+1);
        root->right = recursion(preorder,inorder,index+1,to,curRootIndex+(index-from+1));
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        //helper功能是在前序,中序序列中返回一个根节点
        //参数：前序，中序，中序查找范围（起，终点），前序首节点（即当前根节点）下标
        return recursion(preorder,inorder,0,preorder.size()-1,0);
    }
};