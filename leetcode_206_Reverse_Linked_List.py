class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        curr = head
        node = None
        while curr:
            nxt = curr.next
            curr.next = node
            node = curr
            curr = nxt
            
        return node