import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

N, M = map(int, input().split())
rack = []
for _ in range(M):
    row = list(map(int, input().split()))
    rack.append(row)

def check_safe(x, y):
    if 0 <= x < M and 0 <= y < N:
        return True
    return False

tomato_pos = deque()

def add_start_node():
    for x in range(M):
        for y in range(N):
            if rack[x][y] == 1:
                tomato_pos.append((x, y))

def bfs(tomato_pos):
    while tomato_pos:
        x, y = tomato_pos.popleft()
        for k in range(4):
            new_x = x + dx[k]
            new_y = y + dy[k]
            if check_safe(new_x, new_y):
                if rack[new_x][new_y] == 0:
                    rack[new_x][new_y] = rack[x][y] + 1
                    tomato_pos.append((new_x, new_y))
                
def print_result():
    ans = float('-inf')
    for x in range(M):
        for y in range(N):
            if rack[x][y] == 0:
                print(-1)
                return
            ans = max(ans, rack[x][y])
    print(ans-1)

add_start_node()
bfs(tomato_pos)
print_result()
    