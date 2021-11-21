import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def bfs(start, board, visited):
    x, y = start
    queue = deque()
    queue.append((x, y, 0))
    visited[x][y][0] = 1

    while queue:
        x, y, broken = queue.popleft()

        if x == N-1 and y == M-1:
            return visited[x][y][broken]

        for k in range(4):
            new_x = x + dx[k]
            new_y = y + dy[k]

            if 0 <= new_x < N and 0 <= new_y < M and visited[new_x][new_y][broken] == 0:
                if board[new_x][new_y] == 0:
                    queue.append((new_x, new_y, broken))
                    visited[new_x][new_y][broken] = visited[x][y][broken] + 1
                
                if broken == 0 and board[new_x][new_y] == 1:
                    queue.append((new_x, new_y, 1))
                    visited[new_x][new_y][1] = visited[x][y][0] + 1
    return -1


N, M = map(int, input().strip().split())

board = []
for _ in range(N):
    row = list(map(int, list(input().strip())))
    board.append(row)

visited = [[[0, 0] for _ in range(M)] for _ in range(N)]

print(bfs((0, 0), board, visited))