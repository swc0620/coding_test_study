import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def bfs(x, y):
    global answer
    queue = set([(x, y, board[x][y])])

    while queue:
        x, y, node = queue.pop()
        for k in range(4):
            new_x = x + dx[k]
            new_y = y + dy[k]
            
            if 0 <= new_x < R and 0 <= new_y < C and board[new_x][new_y] not in node:
                queue.add((new_x, new_y, node + board[new_x][new_y]))
                answer = max(answer, len(node)+1)

R, C = map(int, input().split())
board = [list(input().strip()) for _ in range(R)]

answer = 1
bfs(0, 0)
print(answer)