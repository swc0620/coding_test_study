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
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        while (head != null) {
            ListNode next = head.next; // store node 2 to next for next iteration
            head.next = prev; // node 1 points to null
            prev = head; // node 1
            head = next; // node 2
        }
        return prev;
    }
}

/**
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Reverse Linked List.
 * Memory Usage: 38.4 MB, less than 91.31% of Java online submissions for Reverse Linked List.
 */