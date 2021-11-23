import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, -2, -2, -1, 1, 2, 2, 1]
dy = [-2, -1, 1, 2, 2, 1, -1, -2]

def bfs(sx, sy, tx, ty):
    queue = deque()
    queue.append((sx, sy))
    
    if sx == tx and sy == ty:
        return 0

    while queue:
        x, y = queue.popleft()

        for k in range(8):
            nx = x + dx[k]
            ny = y + dy[k]

            if 0 <= nx < l and 0 <= ny < l:
                if board[nx][ny] == 0:
                    queue.append((nx, ny))
                    board[nx][ny] = board[x][y] + 1
                if nx == tx and ny == ty:
                    return board[x][y] + 1

T = int(input().strip())
for _ in range(T):
    l = int(input().strip())
    board = [[0] * l for _ in range(l)]
    sx, sy = map(int, input().strip().split())
    tx, ty = map(int, input().strip().split())
    print(bfs(sx, sy, tx, ty))