import sys
input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

M, N = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(M)]
visited = [[-1]*N for _ in range(M)]

def dfs(x, y):
    if x == M-1 and y == N-1:
        return 1
    if visited[x][y] != -1:
        return visited[x][y]
    visited[x][y] = 0
    for k in range(4):
        nx = x + dx[k]
        ny = y + dy[k]
        if 0 <= nx < M and 0 <= ny < N:
            if board[nx][ny] < board[x][y]:
                visited[x][y] += dfs(nx, ny)
    return visited[x][y]

print(dfs(0, 0))