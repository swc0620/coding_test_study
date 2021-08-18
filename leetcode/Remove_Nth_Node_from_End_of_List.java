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
  public ListNode removeNthFromEnd(ListNode head, int n) {
      ListNode dummy = new ListNode(0, head);
      ListNode slow = dummy, fast = dummy;
      for (int i=1; i<=n+1; ++i)
          fast = fast.next; 
  
      // fast is the n nodes ahead of slow, note that slow is still at dummy
      // 1    2    3    4    5
      // slow     fast
      
      while (fast != null) {
          fast = fast.next;
          slow = slow.next;
      }
      
      slow.next = slow.next.next; // remove nth node from end
      return dummy.next; // real head
  }
}