import sys
N = int(sys.stdin.readline())
sg = list(map(int, sys.stdin.readline().strip().split()))

M = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().strip().split()))

count = {}

for i in range(N):
    if sg[i] in count:
        count[sg[i]] += 1
    else:
        count[sg[i]] = 1

print(' '.join(str(count[nums[i]]) if nums[i] in count else '0' for i in range(M)))