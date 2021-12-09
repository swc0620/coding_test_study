import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [[0]*N for _ in range(N)]
for _ in range(M):
    A, B = map(int, input().split())
    graph[A-1][B-1] = 1
    graph[B-1][A-1] = 1

def bfs(start, visited):
    queue = deque()
    queue.append(start)
    visited[start] = 0
    
    while queue:
        node = queue.popleft()
        for k in range(N):
            if graph[k][node] == 1 and visited[k] == 0:
                queue.append(k)
                visited[k] = visited[node] + 1

res = float('inf')
idx = float('inf')
for i in range(N):
    visited = [0]*N
    bfs(i, visited)
    if sum(visited) < res:
        idx = i
        res = sum(visited)
print(idx+1)