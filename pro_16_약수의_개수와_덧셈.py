import math

def solution(left, right):
    answer = 0
    square = [i*i for i in range(1, 1001)]
    for num in range(left, right+1):
        if num in square:
            answer -= num
        else:
            answer += num

    return answer

# left = int(input())
# right = int(input())
# print(solution(left, right))