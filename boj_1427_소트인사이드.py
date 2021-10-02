nums = list(map(int, list(input())))
nums.sort(reverse=True)
res = ""
for num in nums:
    res += str(num)

print(res)
