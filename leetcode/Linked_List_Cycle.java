/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
import java.util.*;

public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) // 0 or 1 node
            return false;
        if (head.next == head) // points to self
            return true;
        
        HashSet<ListNode> hs = new HashSet<ListNode>();
        ListNode curr = head;
        
        while (curr != null) {
            if (hs.contains(curr)) // revisited
                return true;
            hs.add(curr); // first visit
            curr = curr.next;
        }
        return false;
    }
}

/*
Runtime: 4 ms, faster than 18.56% of Java online submissions for Linked List Cycle.
Memory Usage: 39.7 MB, less than 90.33% of Java online submissions for Linked List Cycle.
*/