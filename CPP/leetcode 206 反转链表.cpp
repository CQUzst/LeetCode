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
    ListNode* reverseList(ListNode* head) 
    {
//迭代
//         if (head == NULL || head->next == NULL)
//             return head;
        
//         ListNode* pre = NULL;
//         ListNode* cur = head;
//         while (cur) //当前位置不为NULL
//         {
//             ListNode* tmpNext = cur->next;
//             cur->next=pre;//当前链接到前一个，即实现反向，最开始的地方指向NULL       
//             pre=cur;//将当前位置更新
//             cur=tmpNext;
//         }
//         return pre;
        
        //递归
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *res=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return res;
    }
};