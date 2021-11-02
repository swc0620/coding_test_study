import sys, copy
from itertools import combinations
from collections import deque
input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def bfs(virus_loc):
    queue = deque(virus_loc)
    while queue:
        node = queue.popleft()
        x, y = node

        for k in range(4):
            new_x = x + dx[k]
            new_y = y + dy[k]
            if 0 <= new_x < N and 0 <= new_y < M and lab2[new_x][new_y] == 0:
                lab2[new_x][new_y] = 2
                queue.append((new_x, new_y))

def count_zero():
    cnt = 0
    for i in range(N):
        for j in range(M):
            if lab2[i][j] == 0:
                cnt += 1
    return cnt

N, M = map(int, input().split())
lab = [[0]*M for _ in range(N)]
virus_loc = []
empty = []
for i in range(N):
    row = list(map(int, input().split()))
    for j in range(M):
        lab[i][j] = row[j]
        if row[j] == 2:
            virus_loc.append((i, j))
        elif row[j] == 0:
            empty.append((i, j))

val = 0
comb = combinations(empty, 3)
for walls in comb:
    lab2 = copy.deepcopy(lab)
    
    wall1, wall2, wall3 = walls
    lab2[wall1[0]][wall1[1]] = 1
    lab2[wall2[0]][wall2[1]] = 1
    lab2[wall3[0]][wall3[1]] = 1
    bfs(virus_loc)
    cnt = count_zero()
    val = max(val, cnt)
print(val)