/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==nullptr)return;
        queue<TreeLinkNode *>q1;
        q1.push(root);
        TreeLinkNode *pre=nullptr;//用来标记每个结点的左边结点
        while(!q1.empty()){
            queue<TreeLinkNode *>q2;//q2记录下一层的节点
            int flag=0;//用来标记是否是每层的第一个元素
            while(!q1.empty())//每层的循环，q1空了说明一层遍历完成
            {
                TreeLinkNode *tmp=q1.front();
                q1.pop();
                if(flag)//每一层第一个节点flag=0，不接，之后每层开始接上
                    pre->next=tmp;
                if(tmp->left)
                    q2.push(tmp->left);
                if(tmp->right)
                    q2.push(tmp->right);
                pre=tmp;
                flag=1;
            }
            q1=q2;
            pre->next=nullptr;//每一层的尾部指向空
        }
    }
};