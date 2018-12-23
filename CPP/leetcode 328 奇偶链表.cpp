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
    ListNode* oddEvenList(ListNode* head) 
    {
        if (!head) //如果为空，直接返回
            return head;
        ListNode* odd = head;
        ListNode* even = head->next;//偶数从第二个开始
        ListNode* evenHead = even;//偶数链表的第一个数
        while (odd->next && even->next) //会循环到底，直到有一个下节点为NULL
        {
            odd->next = even->next;//奇数的下一个节点跳到偶数后面
            odd = odd->next;//更新奇数节点
            even->next = odd->next;//偶数的下一个节点跳到奇数后面
            even = even->next;//更新偶数节点
        }
        odd->next = evenHead;//将奇数结尾的下一个节点连接到偶数起始位置
        return head;
    }
};