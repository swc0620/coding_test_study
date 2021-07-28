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
        ListNode currA=headA;
        ListNode currB=headB;
        while(currA!=null||currB!=null){
            if(currA==currB) return currA;
            currA=currA.next;
            currB=currB.next;
            if(currA==null&&currB!=null){
                currA=headB;
            }
            if(currA!=null&&currB==null){
                currB=headA;
            }
            
        }
        return null;
    }
}