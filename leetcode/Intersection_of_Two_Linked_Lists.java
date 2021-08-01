/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null)
            return null;
        
        ListNode currA = headA;
        ListNode currB = headB;
        
        while (currA != currB) {
            // if currA reaches end of list, it switches to headB; otherwise, steps to the next
            currA = (currA == null) ? headB : currA.next;
            currB = (currB == null) ? headA : currB.next;
        }
        // listA = skipA + common
        // listB = skipB + common
        // currA moves skipA + common + skipB steps
        // currB moves skipB + common + skipA steps
        
        return currA;
    }
}

/**
 * Runtime: 1 ms, faster than 97.64% of Java online submissions for Intersection of Two Linked Lists.
 * Memory Usage: 41.6 MB, less than 79.22% of Java online submissions for Intersection of Two Linked Lists.
 */