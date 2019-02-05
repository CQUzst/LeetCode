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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *sortedHead = new ListNode(-1);
        while(head){
            //保存head位置
            ListNode *next = head->next;
            ListNode *cur = sortedHead;
            while(cur->next && cur->next->val < head->val)//排好序的链表与头节点比较，排序链表往后移，直到找到位置
                cur = cur->next;
            //插入
            head->next = cur->next;
            cur->next = head;
            //恢复head
            head = next;
        }
        return sortedHead->next;
    }
};