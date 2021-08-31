class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None
        
        tail = headA
        while tail.next:
            tail = tail.next
        tail.next = headB
        
        slow = fast = headA
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                fast = headA
                while fast != slow:
                    slow, fast = slow.next, fast.next
                tail.next = None
                return slow
                
        tail.next = None
        return None