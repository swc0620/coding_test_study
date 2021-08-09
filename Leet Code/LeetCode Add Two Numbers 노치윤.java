/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode temp;
        ListNode head;
        if(l1==null&&l2==null) return null;
        if(l1==null) return l2;
        if(l2==null) return l1;
        int prev=0;
        ListNode cur=new ListNode(prev);
        prev=(l1.val+l2.val)/10;
        cur.val+=(l1.val+l2.val)%10;
        temp=cur;
        l1=l1.next;
        l2=l2.next;
        head=temp;
        
        while(l1!=null||l2!=null){
            cur=new ListNode(prev);
            if(l1==null){
                prev=l2.val/10;
                cur.val+=(l2.val)%10;
                if(cur.val>=10){
                    prev+=1;
                    cur.val=cur.val%10;
                }
                
            }
            else if(l2==null){
                prev=l1.val/10;
                cur.val+=(l1.val)%10;
                if(cur.val>=10){
                    prev+=1;
                    cur.val=cur.val%10;
                }
            }
            else{
                prev=(l1.val+l2.val)/10;
                cur.val+=(l1.val+l2.val)%10;
                if(cur.val>=10){
                    prev+=1;
                    cur.val=cur.val%10;
                }
            } 
            temp.next=cur;//새로만든 cur을 temp.next로 지정하고
            temp=temp.next;//temp를 temp.next로 옮김.
            if(l1!=null) l1=l1.next;
            if(l2!=null) l2=l2.next;
        }
        if(prev!=0){
            cur=new ListNode(1);
            temp.next=cur;
        }
        
        return head;
    }
}