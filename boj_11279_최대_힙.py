import sys
N = int(input())

max_heap = []

def percolate(index):
    child = 2 * index + 1
    right_child = 2 * index + 2
    if child < len(max_heap):
        if right_child < len(max_heap) and max_heap[child] < max_heap[right_child]:
            child = right_child
        if max_heap[index] < max_heap[child]:
            max_heap[index], max_heap[child] = max_heap[child], max_heap[index]
            percolate(child)

def insert(element):
    max_heap.append(element)
    n = len(max_heap)
    parent = n // 2
    n -= 1
    parent -= 1
    if parent >= 0:
        while parent >= 0 and n >= 0 and max_heap[parent] < max_heap[n]:
            max_heap[n], max_heap[parent] = max_heap[parent], max_heap[n]
            n = parent
            parent = (n-1) // 2

def remove():
    ans = max_heap[0]
    max_heap[0] = max_heap[-1]
    max_heap.pop()
    percolate(0)
    return ans

while N > 0:
    num = int(sys.stdin.readline())
    if num != 0:
        insert(num)
    else:
        if not max_heap:
            print(0)
        else:
            print(remove())
    N -= 1