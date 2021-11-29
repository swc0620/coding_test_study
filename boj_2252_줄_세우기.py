import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
comparisons = deque()
degrees = [0 for i in range(32001)]
graph = [[] for i in range(32001)]
queue = deque()

for _ in range(M):
    a, b = map(int, input().split())
    comparisons.append((a,  b))

for a, b in comparisons:
    degrees[b] += 1
    graph[a].append(b)

for i in range(1, N+1):
    if degrees[i] == 0:
        queue.append(i)

while queue:
    student = queue.popleft()

    for j in graph[student]:
        degrees[j] -= 1
        if degrees[j] == 0:
            queue.append(j)
    
    print(student, end=' ')