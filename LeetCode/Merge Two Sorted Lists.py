# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        # base case
        if l1 == None and l2 == None:
            return None
        elif not l1: # l1이 빈 리스트인 경우
            return l2
        elif not l2: # l2가 빈 리스트인 경우
            return l1
      
        # 첫 번째 노드 비교
        n1 = l1.val
        node1 = l1
        n2 = l2.val
        node2 = l2

        if n1 < n2: # l1 첫 번째 노드가 더 작은 경우
            start = node1 # 첫 번째 노드 설정
            node1 = node1.next # 다음 노드로 업데이트
        else:
            start = node2
            node2 = node2.next

        # 최종적으로 start를 리턴
        node = start

        # 각 linked list에서 첫 번째 노드 제외 다음 노드가 남아있는 경우
        while not (node1 == None or node2 == None):
            n1 = node1.val
            n2 = node2.val

            if n1 < n2:
                node.next = node1 # 현재 노드의 다음 노드 결정
                node = node1 # 현재 노드 포인터를 다음 노드로 옮김
                node1 = node1.next # 다음 노드로 업데이트(대소 비교용)
            else:
                node.next = node2
                node = node2
                node2 = node2.next

        while not node1 == None: # l1이 남아있는 경우 없어질 때까지 반복
            node.next = node1
            node = node1
            node1 = node1.next
        while not node2 == None: # l2가 남아있는 경우
            node.next = node2
            node = node2
            node2 = node2.next

        return start
