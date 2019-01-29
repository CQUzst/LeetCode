// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */

// //中序遍历，排序，再遍历，值交换
// class Solution {
// public:
//     void recoverTree(TreeNode* root) {
//         inorder(root);
//         vector<int> array(tmp.size());
//         for (int i = 0; i < array.size(); ++i)
//             array[i] = tmp[i] -> val;//将原顺序赋值到数组里
//         sort(array.begin(), array.end());//将array排列好
//         int cnt = 0;//记录两个不一样的值的位置，交换
//         TreeNode* first = nullptr;
//         for (int i = 0; i < array.size(); ++i) {
//             if (tmp[i] -> val != array[i]) {
//                 if (cnt++ < 1) 
//                     first = tmp[i];
//                 else {
//                     swap(first -> val, tmp[i] -> val);
//                     break;
//                 }
//             }
//         }
//     }
//     void inorder(TreeNode* root) //中序遍历，将顺序存在tmp里
//     {
//         if (!root) return;
//         inorder(root -> left);
//         tmp.push_back(root);
//         inorder(root -> right);
//     }
// private:
//     vector<TreeNode*> tmp;
// };

//中序遍历，排序，直接值交换
class Solution {
private:
    vector<TreeNode*> s;
    vector<TreeNode*> s1;
    static bool cmp(const TreeNode* a,const TreeNode*b){
        return a->val<b->val;
    }
public:
    void recoverTree(TreeNode* root) {
       	inorder(root);//中序遍历
        s1=s;
        sort(s1.begin(),s1.end(),cmp);
        TreeNode* p[2];
        int cnt =0;
        for(int i=0;i<s.size()&&cnt<2;i++){
            if(s[i]!=s1[i]){
                p[cnt++]=s[i];
            }
        }
        swap(p[0],p[1]);
    }
    
    void swap(TreeNode* &a ,TreeNode* &b){
         int temp =a->val;
         a->val =b->val;
         b->val =temp;
	}
    
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        s.push_back(root);
        inorder(root->right);
    }
};