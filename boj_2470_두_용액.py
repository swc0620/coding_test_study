N = int(input())
nums = list(map(int, input().split()))


nums.sort()
res = float('inf')
left = 0
right = N-1
two_nums = []
while left < right:
    _sum = nums[left] + nums[right]
    if abs(_sum) < res:
        res = abs(_sum)
        two_nums = [str(nums[left]), str(nums[right])]

    if _sum < 0:
        left += 1
    elif _sum == 0:
        break
    else:
        right -= 1

print(' '.join(two_nums))