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
import java.util.Stack;
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head==null||head.next==null) return head;
        ListNode temp=new ListNode(head.val);
        head=head.next;
        while(head!=null){
            ListNode temp_=new ListNode(head.val, temp);
            temp=temp_;
            head=head.next;
        }
        return temp;
    }
}