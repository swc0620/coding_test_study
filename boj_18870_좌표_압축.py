def binary_search(nums, low, high, target):
    if low <= high:
        mid = (low + high) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] > target:
            return binary_search(nums, low, mid-1, target)
        else:
            return binary_search(nums, mid+1, high, target)
    else:
        return -1

N = int(input())
nums = list(map(int, input().split()))
nums2 = sorted(list(set(nums)))
res = {}
for num in nums2:
    res[num] = binary_search(nums2, 0, len(nums2)-1, num)

result = []
for num in nums:
    result.append(str(res[num]))
print(" ".join(result))