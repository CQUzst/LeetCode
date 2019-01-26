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
		ListNode* curNode = head;
		while (curNode != NULL&& curNode->next != NULL) {
			// 如果当前节点的val和下一节点的val相等，那么将当前节点链接到下下个节点，意思就是抛弃了相同的下一个节点
			if (curNode->val == curNode->next->val) 
				curNode->next = curNode->next->next;
            // 否则就是下一节点和当前节点不相同，那么curNode移位
			else
				curNode = curNode->next;
		}
		return head;
    }
};