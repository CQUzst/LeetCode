/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode node =new ListNode(0);//先生成一个前置节点
        ListNode n1=l1,n2=l2,t=node;//t是新链表的引用
        int sum=0;//sum表示当前位相加之和，/10是取整进入下一位数
        while(n1!=null||n2!=null){
            sum/=10;
            if(n1!=null){
                sum+=n1.val;
                n1=n1.next;
            }
            if(n2!=null){
                sum+=n2.val;
                n2=n2.next;
            }
            t.next=new ListNode(sum%10);//新链表延申节点
            t=t.next;
        }
        if(sum/10!=0)
            t.next=new ListNode(sum/10);
        return node.next;
    }
}
