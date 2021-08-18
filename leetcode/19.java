class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int number=0;
        ListNode cur=head;
        ArrayList<ListNode> listarr = new ArrayList<ListNode>();
        while(cur!=null){
            number++;
            listarr.add(cur);
            cur=cur.next;
        }
        if(number-n==0){
            return listarr.get(0).next;
        }
        listarr.get(number-n-1).next= listarr.get(number-n).next;
        return listarr.get(0);
                
        
    }
}
