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
//         //�ݹ�
//         if(head==NULL || head->next==NULL)
//             return head;
        
//         ListNode *p=head->next;
//         if(p->val!=head->val){//���ظ��ڵ㣬����ݹ�
//             head->next=deleteDuplicates(p);
//             return head;
//         }
//         else{//��ǰ��һ���ڵ��ظ��ˣ�������һ�����ظ��Ľڵ㿪ʼ�ݹ�
//             while(p && p->val==head->val) 
//                 p=p->next;
//             return deleteDuplicates(p);
//         }
        
        //����
        if(head==NULL || head->next==NULL)
            return head;

        ListNode dummy(0);
        auto pre = &dummy;
        pre->next = head;
        while(pre->next && pre->next->next) {
            if(pre->next->val == pre->next->next->val) {//���ظ��ģ��ȼ�¼һ���ظ�ֵ
                int value = pre->next->val;
                while(pre->next && value == pre->next->val) {//ȥ���ظ�ֵ����value�ظ�������ֵ������
                    pre->next = pre->next->next;
                }
            }
            else  
                pre = pre->next;
        }
        return dummy.next;
    }
};