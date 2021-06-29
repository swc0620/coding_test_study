import sys

N, M = list(map(int, sys.stdin.readline()[:-1].split()))

circular_queue = [N-i for i in range(N)]

nums = list(map(int, sys.stdin.readline()[:-1].split()))
count = 0

for i in range(M):
    # print(circular_queue)
    if circular_queue[-1] == nums[i]:
        circular_queue.pop()
    else:
        index = circular_queue.index(nums[i]) 
        length = len(circular_queue)
        if index < length // 2:
            count += index + 1
            temp1 = circular_queue[index + 1:]
            temp2 = circular_queue[:index]
            circular_queue = temp1 + temp2
        else:
            count += length - index - 1
            temp1 = circular_queue[index + 1:]
            temp2 = circular_queue[:index]
            circular_queue = temp1 + temp2
print(count, end="")