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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;//两个指针，一个先走n步
        ListNode *low  = head;//后走n步，当先走指针到尾时候，slow到达倒数第n个
        ListNode *pre = NULL;
        if(head == NULL)
        {
            return NULL;   //输入的链表为空；
        }
        
        for(int i = 0; i < n-1; i ++)//先到第n的位置
        {
            if(fast->next)
            {
                fast = fast->next;
            }
        }

        while(fast->next)//pre保存的是需要删除的那个结点的上一个结点
        {
            fast = fast->next;
            pre  = low;      
            low  = low->next;
        }

        if(low == head)   //删除的那个结点是头结点。
        {
            head = head->next;
        }
        else
        {
            delete low;
            pre->next = pre->next->next;
        }

        return head;
    }
};