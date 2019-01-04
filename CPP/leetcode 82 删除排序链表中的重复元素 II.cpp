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
    ListNode* deleteDuplicates(ListNode* head) {
//         //递归
//         if(head==NULL || head->next==NULL)
//             return head;
        
//         ListNode *p=head->next;
//         if(p->val!=head->val){//非重复节点，进入递归
//             head->next=deleteDuplicates(p);
//             return head;
//         }
//         else{//和前面一个节点重复了，进入下一个不重复的节点开始递归
//             while(p && p->val==head->val) 
//                 p=p->next;
//             return deleteDuplicates(p);
//         }
        
        //迭代
        if(head==NULL || head->next==NULL)
            return head;

        ListNode dummy(0);
        auto pre = &dummy;
        pre->next = head;
        while(pre->next && pre->next->next) {
            if(pre->next->val == pre->next->next->val) {//有重复的，先记录一下重复值
                int value = pre->next->val;
                while(pre->next && value == pre->next->val) {//去掉重复值，与value重复的所有值都跳过
                    pre->next = pre->next->next;
                }
            }
            else  
                pre = pre->next;
        }
        return dummy.next;
    }
};