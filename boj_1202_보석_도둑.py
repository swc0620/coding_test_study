import sys, heapq
input = sys.stdin.readline

N, K = map(int, input().split())
jewelries = []
bags = []
for _ in range(N):
    M, V = map(int, input().split())
    heapq.heappush(jewelries, (M, V))
for _ in range(K):
    C = int(input())
    heapq.heappush(bags, C)

val = 0
available = []
for _ in range(K):
    capa = heapq.heappop(bags)

    while jewelries and jewelries[0][0] <= capa:
        mass, value = heapq.heappop(jewelries)
        heapq.heappush(available, -value)
    
    if available:
        val -= heapq.heappop(available)
    elif not jewelries:
        break

print(val)