from collections import Counter

N = int(input())

nums = []
for _ in range(N):
    nums.append(int(input()))

nums.sort()

counter = Counter(nums)
common = counter.most_common()
if len(nums) > 1:
    if common[0][1] == common[1][1]:
        mode = common[1][0]
    else:
        mode = common[0][0]
else:
    mode = common[0][0]


print(round(sum(nums) / len(nums)))
print(nums[len(nums)//2])
print(mode)
print(max(nums) - min(nums))

