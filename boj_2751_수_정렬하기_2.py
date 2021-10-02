def partition(nums, low, high):
    i = low - 1
    pivot = nums[high]

    for j in range(low, high):
        if nums[j] < pivot:
            i += 1
            nums[i], nums[j] = nums[j], nums[i]

    nums[i+1], nums[high] = nums[high], nums[i+1]
    return i+1

def quick_sort(nums, low, high):
    if len(nums) == 1:
        return nums

    if low < high:
        pivot = partition(nums, low, high)
        quick_sort(nums, low, pivot-1)
        quick_sort(nums, pivot+1, high)


N = int(input())

nums = []

for _ in range(N):
    nums.append(int(input()))

quick_sort(nums, 0, N-1)

for i in range(N):
    print(nums[i])

    