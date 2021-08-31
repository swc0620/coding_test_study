target = 1
for _ in range(3):
    target *= int(input())

nums = {'0': 0, '1': 0, '2': 0, '3': 0, '4': 0, '5': 0, '6': 0, '7': 0, '8': 0, '9': 0}
for i in str(target):
    nums[i] += 1

print(*nums.values(), sep='\n')