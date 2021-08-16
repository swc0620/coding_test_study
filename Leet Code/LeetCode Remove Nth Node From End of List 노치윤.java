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
        Stack<ListNode> stack=new Stack<>();
        ListNode curr=head;
        while(curr!=null){
            stack.push(curr);
            curr=curr.next;
        }
        for(int i=0;i<n-1;i++){
            stack.pop();
        }
        if(!stack.isEmpty()){
            ListNode remove_node=stack.pop();
            if(remove_node==head){//head는 prev노드가 없기에 따로 처리
                return head.next;
            }
            ListNode prev=stack.peek();
            prev.next=remove_node.next;
            return head;            
        }
        return null;
    }
}