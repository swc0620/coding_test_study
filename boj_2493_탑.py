import sys
input = sys.stdin.readline

N = int(input())
towers = list(map(int, input().strip().split()))
stack = []
ans = [0] * N
for i in range(N):
    sig_tower = towers[i]
    if stack:
        while stack:
            if sig_tower > stack[-1][0]:
                stack.pop()
            elif sig_tower < stack[-1][0]:
                print(stack[-1][1]+1, end=" ")
                break
        if not stack:
            print(0, end=" ")
        stack.append((sig_tower, i))
    else:
        print(0, end=" ")
        stack.append((sig_tower, i))
