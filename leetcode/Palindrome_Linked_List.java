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
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null)
          return true;

        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = null; // prev node of slow; stores reversely connected nodes of the first half of list
        
        while (fast != null && fast.next != null) {
            // make fast reach the end of list so that slow reaches end of list
            // advance fast, two steps at a time so that it is always ahead of slow
            fast = fast.next.next;
            // reverse the first half list
            ListNode nextSlow = slow.next;
            slow.next = prev; // reverse
            // advance prev and slow
            prev = slow;
            slow = nextSlow;
        }
        
        // when a list has an odd number of nodes
        if (fast != null)
            slow = slow.next; // skip ahead of middle node
        
        // now prev marks the end of the first half, slow marks the beginning of the second half
        
        // compare slow and prev
        while (prev != null) {
            if (prev.val != slow.val)
                return false;
            // advance both
            prev = prev.next;
            slow = slow.next;
        }
        return true;
    }
}

/**
Runtime: 3 ms, faster than 99.99% of Java online submissions for Palindrome Linked List.
Memory Usage: 49.2 MB, less than 68.61% of Java online submissions for Palindrome Linked List.
*/