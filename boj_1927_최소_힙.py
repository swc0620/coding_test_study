import sys
N = int(input())

min_heap = []

def percolate(index):
    child = 2 * index + 1
    right_child = 2 * index + 2
    if child < len(min_heap):
        if right_child < len(min_heap) and min_heap[child] > min_heap[right_child]:
            child = right_child
        if min_heap[index] > min_heap[child]:
            min_heap[index], min_heap[child] = min_heap[child], min_heap[index]
            percolate(child)

def insert(element):
    min_heap.append(element)
    n = len(min_heap)
    parent = n // 2
    n -= 1
    parent -= 1
    if parent >= 0:
        while parent >= 0 and n >= 0 and min_heap[parent] > min_heap[n]:
            min_heap[n], min_heap[parent] = min_heap[parent], min_heap[n]
            n = parent
            parent = (n-1) // 2

def remove():
    ans = min_heap[0]
    min_heap[0] = min_heap[-1]
    min_heap.pop()
    percolate(0)
    return ans

while N > 0:
    num = int(sys.stdin.readline())
    if num != 0:
        insert(num)
    else:
        if not min_heap:
            print(0)
        else:
            print(remove())
    N -= 1