#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) :val(x){}
};

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
    ListNode* reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL)
            return NULL;

        ListNode *leftBoundNode = NULL;//leftBoundNode为m的左节点
        ListNode *cur = head;
        for(int i = 1; i < m; i++){
            leftBoundNode = cur;
            cur = cur->next;
        }
        ListNode *mNode = cur;//记录m节点位置
        ListNode *curPre = cur;//记录当前节点之前的节点
        cur = cur->next;//反转链表会将cur的前面一个节点反转到,所以要在m的后一个位置开始
        for(int i = m + 1; i <= n; i++)//进行链表反转
        {
            ListNode *temp = cur->next;
            cur->next = curPre;
            curPre =cur;//反转到最后一步时候，curPre就是n节点了
            cur = temp;//最后情况cur是n节点的后一个节点
        }

        mNode->next = cur;//翻转后m在后面，m节点连接到原来n节点的后面一个节点
        if (leftBoundNode)//如果m的左边节点存在，左边界节点接到翻转后的n节点位置
            leftBoundNode->next = curPre;
        else//如果m节点左边节点不存在，就从n节点开始了
            head = curPre;
        return head;
    }
};
int main()
{
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* forth = new ListNode(4);
    ListNode* fifth = new ListNode(5);
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = NULL;
    Solution s;
    s.reverseBetween(first,2,4);

    return 0;
}
