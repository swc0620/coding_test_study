from collections import Counter

N = int(input())
nums = []
for _ in range(N):
    nums.append(int(input()))

counter = Counter(nums)
common_count = counter.most_common()
common_count.sort(key=lambda count: (-count[1], count[0]))
print(common_count[0][0])