import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, 0, 1, 0, 0, 0]
dy = [0, 1, 0, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]

N, M, H = map(int, input().split())
board = []
for _ in range(H):
    z = []
    for _ in range(M):
        x = list(map(int, input().strip().split()))
        z.append(x)
    board.append(z)

def bfs(visited, queue):
    while queue:
        x, y, z = queue.popleft()

        for k in range(6):
            nx = x + dx[k]
            ny = y + dy[k]
            nz = z + dz[k]

            if 0 <= nx < M and 0 <= ny < N and 0 <= nz < H:
                if board[nz][nx][ny] == 0 and visited[nz][nx][ny] == 0:
                    queue.append((nx, ny, nz))
                    visited[nz][nx][ny] = visited[z][x][y] + 1


queue = deque()
visited = [[[0]*N for _ in range(M)] for _ in range(H)]
for x in range(M):
    for y in range(N):
        for z in range(H):
            if board[z][x][y] == 1:
                queue.append((x, y, z))
                visited[z][x][y] = 1

bfs(visited, queue)

def cal_result(board):
    max_val = float('-inf')
    for x in range(M):
        for y in range(N):
            for z in range(H):
                if board[z][x][y] != -1 and visited[z][x][y] == 0:
                    return -1
                max_val = max(max_val, visited[z][x][y])
    return max_val-1

print(cal_result(board))
    