/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(!pRoot)
            return;
        if(pRoot->left&&pRoot->right){
            TreeNode *tmp;
            tmp=pRoot->right;
            pRoot->right=pRoot->left;
            pRoot->left=tmp;
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
        else if(pRoot->left){
            pRoot->right=pRoot->left;
            pRoot->left=NULL;
            Mirror(pRoot->right);
        }
        else if(pRoot->right){
            pRoot->left=pRoot->right;
            pRoot->right=NULL;
            Mirror(pRoot->left);
        }
        return;
    }
};
