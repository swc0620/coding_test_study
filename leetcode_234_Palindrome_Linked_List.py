class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head.next:
            return True
        queue = []
        curr = head
        while curr:
            queue.append(curr.val)
            curr = curr.next
        while queue:
            temp1 = queue.pop(0)
            if queue:
                temp2 = queue.pop()
            else:
                return True
            if temp1 != temp2:
                return False
        return True
        