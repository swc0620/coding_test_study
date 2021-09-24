import sys
N, K = map(int, sys.stdin.readline().split())
count = 0
for i in range(1, N+1):
    if count == K:
        break
    q, r = divmod(N, i)
    if r == 0:
        count += 1
    # print(N, i, r, count)

if count == K:
    if i == N:
        print(i)
    else:
        print(i-1)
else:
    print(0)