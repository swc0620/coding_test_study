from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int, input().split())

graph = [[0] * N for _ in range(N)]

for _ in range(M):
    u, v = map(int, input().split())
    graph[u-1][v-1] = 1
    graph[v-1][u-1] = 1


def bfs(start, visited):
    queue = deque()
    queue.append(start)
    visited[start] = True
    while queue:
        node = queue.popleft()
        for c in range(N):
            if graph[node][c] == 1 and visited[c] == False:
                queue.append(c)
                visited[c] = True
    return visited

visited = {i:False for i in range(N)}
cnt = 0

for c in visited.keys():
    if visited[c] == False:
        bfs(c, visited)
        cnt += 1

print(cnt)
        