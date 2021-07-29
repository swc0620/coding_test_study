# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def createStack(self, head: ListNode) -> List[ListNode]:
        stack = []
        while head:
            stack.append(head)
            head = head.next
        return stack
    
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if headA and headB:
            stackA = self.createStack(headA)
            stackB = self.createStack(headB)
            intersection = True
            prev = None
            
            while stackA and stackB:
                topA = stackA.pop()
                topB = stackB.pop()
                if topA != topB: 
                    if intersection == False: # 공통된 노드가 없다는 의미
                        return
                    else: # prev는 공통된 노드
                        return prev
                else:
                    intersection = True
                    prev = topA
                
            return prev
        else:
            return
