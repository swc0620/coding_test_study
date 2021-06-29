import sys
N, K = list(map(int, sys.stdin.readline()[:-1].split()))
table = [i+1 for i in range(N)]

result = []
r = 0

while N > 0:
    r += (K - 1)
    if r >= len(table):
        r %= len(table)
    result.append(str(table[r]))
    table = table[:r] + table[r+1:]
    N -= 1

print("<", ", ".join(result), ">", sep="", end="")