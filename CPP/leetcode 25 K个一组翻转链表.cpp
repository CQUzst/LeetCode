// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
            // -1->1->2->3->4->5
            //  |           |
            // pre         next

            // -1->3->2->1->4->5
            //           |  |
            //        pre next
        
        if (!head || k == 1) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy, *cur = head;
        dummy->next = head;
        int i = 0;
        while (cur) {//当前指针移动，当有k个时将当前链表反转
            ++i;
            if (i % k == 0) {
                pre = reverseOneGroup(pre, cur->next);
                cur = pre->next;
            } else 
                cur = cur->next;
        }
        return dummy->next;
    }
    
private:
    ListNode *reverseOneGroup(ListNode *pre, ListNode *next) {
        ListNode *last = pre->next;
        ListNode *cur = last->next;
        while(cur != next) {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }
        return last;

    }
};
