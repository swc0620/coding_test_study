N, K = list(map(int, input().split()))
nums = []
for _ in range(N):
    i, gold, silv, bron = list(map(int, input().split()))
    nums.append((i, gold, silv, bron))

nums.sort(key=lambda nation: (-nation[1], -nation[2], -nation[3]))

for i in range(N):
    if nums[i][0] == K:
        idx = i
for i in range(N):
    if nums[i][1:] == nums[idx][1:]:
        print(i+1)
        break
    