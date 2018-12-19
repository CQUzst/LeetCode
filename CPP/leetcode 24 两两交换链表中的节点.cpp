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
    ListNode* swapPairs(ListNode* head) {
        //要有一个节点指向要交换的两个节点中第一个的前一个节点，避免链表断开
        ListNode *temp = new ListNode(0);//防止链断开设置的节点
        temp->next = head;//放在头结点之前，头结点是首先要交换的两个节点的前一个节点
        ListNode *res = temp;//用于最后返回结果 因为temp会改变
        while(temp->next != NULL && temp->next->next != NULL)//后两个非空，说明可以交换
        {
            ListNode *p1 = temp->next;//要交换节点1 
            ListNode *p2 = temp->next->next;//要交换节点2 
            temp->next = p2;
            p1->next = p2->next;
            p2->next = p1;
            temp = p1;
        }
        return res->next;
    }
};