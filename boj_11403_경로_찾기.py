from collections import deque
import sys
input = sys.stdin.readline

def bfs(start):
    visited = [0 for _ in range(N)]
    queue = deque()
    queue.append(start)
    while queue:
        node = queue.popleft()
        for i in range(N):
            if visited[i] == 0 and graph[node][i] == 1:
                visited[i] = 1
                res[start][i] = 1
                queue.append(i)


N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
res = [[0]*N for _ in range(N)]
for i in range(N):
    bfs(i)

for row in res:
    res2 = list(map(str, row))
    print(' '.join(res2))
