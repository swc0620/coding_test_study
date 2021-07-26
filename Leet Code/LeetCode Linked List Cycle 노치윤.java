
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode NIL=new ListNode(200000);//체크한 노드는 모두 NIL을 가리키도록.
        ListNode curr=head;
        if(head==null) return false;
        while(true){
            ListNode temp=new ListNode();
            temp=curr.next;
            if(temp==null) return false;
            if(temp==NIL) return true;//만일 temp가 NIL을 가리킨다면 이미 체크한 노드! 즉 circular
            curr.next=NIL;
            curr=temp;
        }
    }
}