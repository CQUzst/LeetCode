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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        //递归排序，选每次首位数值比较，小的列为head
        if(l1 == NULL && l2 == NULL)
             return NULL;
        if(l1 == NULL)
             return l2;
         if(l2 == NULL)
             return l1;
         ListNode *head = NULL;
         if(l1->val > l2->val)
         {
              head = l2;
              head->next = mergeTwoLists(l1, l2->next);
         }
         else
        {
             head = l1;
             head->next = mergeTwoLists(l1->next, l2);
         }
         return head;
    }
};