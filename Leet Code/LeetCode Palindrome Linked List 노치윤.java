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
        if(head==null) return true;
        ListNode temp_=head;
        ListNode temp=new ListNode(head.val);
        while(temp_.next!=null){
            temp=new ListNode(temp_.next.val, temp);
            temp_=temp_.next;
        }
        //문자열 뒤집고 비교.
        while(temp.next!=null){
            if(head.val==temp.val){
                head=head.next;
                temp=temp.next;
            }
            else{
                return false;
            }
        }
        return true;
    }
}