N = int(input())
nums = list(map(int, input().split()))
max_num = max(nums)

sieve = [False, False] + [True] * (max_num - 1)

for i in range(max_num+1):
    if sieve[i]:
        for j in range(2*i, max_num+1, i):
            sieve[j] = False
cnt = 0
for num in nums:
    if sieve[num]:
        cnt += 1
print(cnt)