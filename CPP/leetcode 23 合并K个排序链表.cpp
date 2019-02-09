/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int length = lists.size();
        if (length == 0)
            return NULL;
        else if(length == 1)
            return lists[0];
        else if(length == 2)
            return mergeTwoLists(lists[0], lists[1]);

        //分治，不断将链表总数一分为二，再返回合并链表
        vector<ListNode*> leftHalf(lists.begin(), lists.begin()+length/2);
        vector<ListNode*> rightHalf(lists.begin()+length/2, lists.end());
        return mergeTwoLists(mergeKLists(leftHalf), mergeKLists(rightHalf));
    }
    
    //两个列表合并并排序
    ListNode* mergeTwoLists(ListNode* left,ListNode* right){
        if(!left&&!right) return nullptr;
        if(!left) return right;
        if(!right) return left;
        ListNode* head;
        if(left->val<right->val){
            head=left;
            head->next=mergeTwoLists(left->next,right);
        }
        else{
            head=right;
            head->next=mergeTwoLists(left,right->next);
        }
        return head;
    }
//     ListNode* mergeTwoLists(ListNode* left, ListNode* right)
//     {
//         if(left == NULL && right == NULL)       //  两个链表均为空
//             return NULL;
//         else if(left != NULL && right == NULL)  //  left不为空, right为空
//             return left;
//         else if(left == NULL && right != NULL)  //  left为空, right不为空
//             return right;

//         //  先生成头结点
//         ListNode *head = NULL;
//         if(left->val < right->val){
//             head = left;
//             left = left->next;
//             //cout <<left->val <<"in list" <<endl;
//         }
//         else{
//             head = right;
//             right = right->next;
//             //cout <<right->val <<"in list" <<endl;
//         }

//         //遍历两个链表
//         ListNode *curr = head;
//         while(left != NULL && right != NULL){
//             //每次找到一个小的加入新的链表
//             if(left->val < right->val){
//                 curr->next = left;
//                 curr = curr->next;
//                 left = left->next;
//             }
//             else{
//                 curr->next = right;
//                 curr = curr->next;
//                 right = right->next;
//             }
//         }

//         //处理较长链表的剩余部分
//         if(left != NULL)
//             curr->next = left;
//         else
//             curr->next = right;
//         return head;
//     }
};
