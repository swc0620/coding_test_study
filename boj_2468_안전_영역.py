from copy import deepcopy
from collections import deque
import sys
input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def bfs(start, visited, rain):
    queue = deque()
    queue.append(start)
    x, y = start
    visited[x][y] = 1

    while queue:
        x, y = queue.popleft()
        
        for i in range(4):
            new_x = x + dx[i]
            new_y = y + dy[i]
        
            if 0 <= new_x < N and 0 <= new_y < N:
                if region[new_x][new_y] >= rain and visited[new_x][new_y] == 0:
                    visited[new_x][new_y] = 1
                    queue.append((new_x, new_y))

N = int(input())
region = []
for _ in range(N):
    row = list(map(int, input().split()))
    region.append(row)


min_height = min(map(min, region))
max_height = max(map(max, region))

max_cnt = float('-inf')
for rain in range(min_height, max_height+1):
    visited = [[0] * N for _ in range(N)]
    cnt = 0
    for x in range(N):
        for y in range(N):
            if region[x][y] >= rain and visited[x][y] == 0:
                bfs((x,y), visited, rain)
                cnt += 1
    max_cnt = max(max_cnt, cnt)

print(max_cnt)