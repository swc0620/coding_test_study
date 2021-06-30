import sys
k = int(sys.stdin.readline())
nums_list = []
for _ in range(k):
    num = int(input())
    if num == 0:
        nums_list.pop()
    else:
        nums_list.append(num)
        
print(sum(nums_list))