#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 class Solution {
 public:
     ListNode* reverseKGroup(ListNode* head, int k) {
             // -1->1->2->3->4->5
             //  |  |         |
             //pre last        next

             // -1->3->2->1->4->5
             //           |  |
             //         last next

         if (!head || k == 1)
             return head;
         ListNode *dummy = new ListNode(-1);
         ListNode *pre = dummy, *cur = head;
         dummy->next = head;

         int i = 0;
         while (cur) {//当前指针(cur)移动，当有k个时将当前链表反转
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
     //pre是k链表的前一个节点，next为k链表后一个节点，返回的是翻转后的最后一个节点
     ListNode *reverseOneGroup(ListNode *pre, ListNode *next) {
         ListNode* last=pre->next;
         ListNode* cur=last->next;
         while(cur!=next){
             last->next=cur->next;//将last一直往后进行交换
             cur->next=pre->next;//末尾的数一直拿到前面来，然后接上之前的末位数
             pre->next=cur;
             cur=last->next;
             ListNode *show=pre->next;
             while(show){
                 cout<<show->val<<"  ";
                 show=show->next;
             }
             cout<<endl;
         }
         return last;
     }
 };

int main(   )
{
    Solution s;
    ListNode he(0),tw(0),thr(0),fou(0),fiv(0);
    ListNode *head=&he,*two=&tw,*three=&thr,*four=&fou,*five=&fiv;
    head->next=two;
    two->next=three;
    three->next=four;
    four->next=five;
    head->val=1;
    two->val=2;
    three->val=3;
    four->val=4;
    five->val=5;
    int k =4;

    s.reverseKGroup(head,k);
    return 0;
}
