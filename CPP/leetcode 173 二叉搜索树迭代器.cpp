/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode *> s;
public:
    BSTIterator(TreeNode* root) {
        while(root)//循环将左子树压入栈中
        {
            s.push(root);
            root=root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int res;//取出栈顶元素，即最小值，再将最小值右子树的所有左子树压入栈中
        TreeNode *temp=s.top();
        s.pop();
        res=temp->val;
        temp=temp->right;
        while(temp){
            s.push(temp);
            temp=temp->left;
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */