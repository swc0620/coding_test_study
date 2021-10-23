from collections import deque

N, K = map(int, input().split())
line = [0]*100001

def bfs(start, target):
    queue = deque()
    queue.append(start)
    while queue:
        now = queue.popleft()
        if now == target:
            return line[now]
        next1 = now - 1
        next2 = now + 1
        next3 = now * 2
        if 0 <= next1 <= 100000 and line[next1] == 0:
            line[next1] = line[now] + 1
            queue.append(next1)
        if 0 <= next2 <= 100000 and line[next2] == 0:
            line[next2] = line[now] + 1
            queue.append(next2)
        if 0 <= next3 <= 100000 and line[next3] == 0:
            line[next3] = line[now] + 1
            queue.append(next3)

res = bfs(N, K)
print(res)