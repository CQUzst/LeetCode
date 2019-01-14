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
    bool hasCycle(ListNode *head) {
        if(!head)  return false;  
        ListNode *fast = head,*slow = head;  
        while(fast!=NULL&&fast->next!=NULL){   
            fast = fast->next->next;  
            slow = slow->next;  
            if(fast==slow)  
                return true;  
        }    
        return false; 
        
        // unordered_map<ListNode*, bool> m;
        // while (head != NULL){
        //     if (m[head]==true)
        //         return true;
        //     else
        //         m[head] = true;
        //     head = head->next;
        // }
        return false;
        // unordered_map<ListNode*, int> m;
        // while (head != NULL){
        //     if (m.count(head))
        //         return true;
        //     else
        //         m[head] = 1;
        //     head = head->next;
        // }
        // return false;
    }
};