import sys
N, M = list(map(int, sys.stdin.readline()[:-1].split()))

ddeutdo = [sys.stdin.readline().strip() for _ in range(N)]
bodo = [sys.stdin.readline().strip() for _ in range(M)]

ddbd = list(set(ddeutdo).intersection(set(bodo)))

print(len(ddbd))
ddbd.sort()
print(*ddbd, sep="\n")

