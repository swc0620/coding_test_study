import sys
from collections import deque
input = sys.stdin.readline


n = int(input())
graph = [[0]*n for _ in range(n)]
a, b = map(int, input().split())
count = [-1]*n
m = int(input())
for _ in range(m):
    x, y = map(int, input().split())
    graph[x-1][y-1] = 1
    graph[y-1][x-1] = 1

def bfs(start, end):
    queue = deque()
    queue.append(start)
    count[start] = 0

    while queue:
        node = queue.popleft()

        for k in range(n):
            if graph[node][k] == 1 and count[k] == -1:
                count[k] = count[node] + 1
                queue.append(k)
        
        if count[end] != -1:
            print(count[end])
            break
    else:
        print(-1)

bfs(a-1, b-1)