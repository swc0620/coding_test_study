nums = list(map(int, list(input())))
if 0 not in nums or sum(nums) % 3 != 0:
    print(-1)
else:
    nums.sort(reverse=True)
    res = ""
    for n in nums:
        res += str(n)
    print(res)