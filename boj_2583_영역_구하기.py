import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def bfs(x, y):
    cnt = 1
    queue = deque()
    queue.append((x, y))

    while queue:
        x, y = queue.popleft()
        board[x][y] = 1

        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]

            if 0 <= nx < M and 0 <= ny < N:
                if board[nx][ny] == 0 and (nx, ny) not in queue:
                    queue.append((nx, ny))
                    board[nx][ny] == 1
                    cnt += 1
    return cnt

M, N, K = map(int, input().strip().split())
board = [[0]*N for _ in range(M)]
for _ in range(K):
    y1, x1, y2, x2 = map(int, input().strip().split())
    x1 = M - x1
    x2 = M - x2
    for x in range(x2, x1):
        for y in range(y1, y2):
            board[x][y] = 1

area = []
cnt = 0
for x in range(M):
    for y in range(N):
        if board[x][y] == 0:
            area_cnt = bfs(x, y)
            cnt += 1
            area.append(area_cnt)
print(cnt)
area.sort()
area = list(map(str, area))
print(' '.join(area))