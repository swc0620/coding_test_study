import sys
from collections import deque
from copy import copy
input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def bfs(start, board, visited):
    x, y = start
    queue = deque()
    queue.append(start)

    while queue:
        x, y = queue.popleft()

        for k in range(4):
            new_x = x + dx[k]
            new_y = y + dy[k]

            if 0 <= new_x < N and 0 <= new_y < N and visited[new_x][new_y] == 0 and board[x][y] == board[new_x][new_y]:
                queue.append((new_x, new_y))
                visited[new_x][new_y] = 1

N = int(input())

ncb_board = []
cb_board = []
for _ in range(N):
    row = list(input().strip())
    ncb_board.append(row)
    row2 = copy(row)
    for idx, col in enumerate(row2):
        if col == 'G':
            row2[idx] = 'R'
    cb_board.append(row2)

ncb_visited = [[0]*N for _ in range(N)]
cb_visited = [[0]*N for _ in range(N)]

ncb_cnt = 0
cb_cnt = 0
for x in range(N):
    for y in range(N):
        if ncb_visited[x][y] == 0:
            bfs((x, y), ncb_board, ncb_visited)
            ncb_cnt += 1
        if cb_visited[x][y] == 0:
            bfs((x, y), cb_board, cb_visited)
            cb_cnt += 1

print(ncb_cnt, cb_cnt)
