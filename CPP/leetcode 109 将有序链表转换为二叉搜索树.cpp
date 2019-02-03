/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
//     TreeNode* sortedListToBST(ListNode* head) {
//         vector<int> array;
//         while(head){
//             array.push_back(head->val);
//             head=head->next;
//         }
//         int n=array.size();
//         TreeNode* root;
//         return recursion(0,n-1,array);
//     }
// private:
//     TreeNode* recursion(int start,int end,vector<int> array){
//         if(start>end)
//              return nullptr;
//         int mid=(start+end)/2;
//         TreeNode *root=new TreeNode(array[mid]);
//         TreeNode *left=recursion(start,mid-1,array);
//         TreeNode *right=recursion(mid+1,end,array);
//         root->left=left;
//         root->right=right;
//         return root;
//     }
// };
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> array;
        while(head){
            array.push_back(head->val);
            head=head->next;
        }
        int n=array.size();
        TreeNode* root;
        return recursion(array);
    }
private:
    TreeNode* recursion(vector<int> &array){
        if(array.empty())
             return nullptr;
        int mid=array.size()/2;
        TreeNode *root=new TreeNode(array[mid]);
        vector<int> vec_left=vector<int>(array.begin(),array.begin()+mid);
        vector<int> vec_right=vector<int>(array.begin()+mid+1,array.end());
        TreeNode *left=recursion(vec_left);
        TreeNode *right=recursion(vec_right);
        root->left=left;
        root->right=right;
        return root;
    }
};