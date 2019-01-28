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
//     vector<int> postorderTraversal(TreeNode* root) {
//         if(root){
//             postorderTraversal(root->left);
//             postorderTraversal(root->right);
//             res.push_back(root->val);
//         }
//         return res;
//     }
// private:
//     vector<int> res;
// };


//方案一：当前节点被读取的条件为：无左右孩子，或者上一次读取的为其子树。
//否则按照先右后左的方式对子节点压栈。
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root){
        vector<int> res;
        if(!root)  
            return res;
        stack<TreeNode *> st;
        TreeNode * pre = nullptr;
        st.push(root);
        while(!st.empty()){
            TreeNode * p = st.top();
            if( (!p->left && !p->right) ||
                    (pre && (pre == p->left || pre == p->right)) ){
                res.push_back(p->val);
                st.pop();
                pre = p;
            }
            else{
                if(p->right) st.push(p->right);
                if(p->left) st.push(p->left);
            }
        }
        return res;        
    }
};

// //方案二：后序遍历有一种巧妙的方式：前序遍历根节点，先后将左右子节点压栈。
// //这样的遍历顺序为：中，右，左。最后reverse结果，则遍历结果变为：左，右，中
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int>res;
//         if(!root) 
//             return res;
//         stack<TreeNode *>st;
//         st.push(root);
//         while (!st.empty()){
//             TreeNode *node = st.top();
//             st.pop();
//             res.push_back(node->val);//先取中值
//             if (node->left)//堆栈先入后出，先放左，左后取值，即再取右值，最后取左值
//                 st.push(node->left);
//             if (node->right)
//                 st.push(node->right);
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };