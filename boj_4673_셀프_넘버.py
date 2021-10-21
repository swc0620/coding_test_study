from collections import deque

nums = deque([i for i in range(1, 10001)])
def wrapper(n):
    def self_num(n):
        num = n
        while num > 0:
            num, r = divmod(num, 10)
            n += r
        return n
    while True:
        n = self_num(n)
        if n in nums:
            nums.remove(n)
        else:
            break
        

i = 0
while True:
    if i >= len(nums):
        break
    wrapper(nums[i])
    if i >= len(nums):
        break
    i += 1
for num in nums:
    print(num)