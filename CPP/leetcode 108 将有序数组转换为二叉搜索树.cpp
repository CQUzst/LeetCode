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
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         return creat(nums, 0, nums.size()-1);  
//     }
// private:
//     TreeNode* creat(vector<int> nums, int left, int right){  
//         //二分法
//         if(left > right) 
//             return nullptr;  
//         int mid = (left+right)/2;  
//         TreeNode *root = new TreeNode(nums[mid]);  
//         root->left = creat(nums, left, mid-1);  
//         root->right = creat(nums, mid+1, right);  
//         return root;  
//     }
// };
//下面更快，从数组层面进行二分效率更高
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
            return nullptr;   
        int mid=nums.size()/2;
        TreeNode* root=new TreeNode(nums[mid]);
        vector<int> vec_l=vector<int>(nums.begin(),nums.begin()+mid);
        vector<int> vec_r=vector<int>(nums.begin()+mid+1,nums.end());
        
        root->left=sortedArrayToBST(vec_l);
        root->right=sortedArrayToBST(vec_r);
        return root; 
    }
};