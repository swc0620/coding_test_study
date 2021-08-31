from math import prod

def solution(a, b):
    answer = 0
    for index in zip(a, b):
        answer += prod(index)
    return answer

# a = list(map(int, input().split(",")))
# b = list(map(int, input().split(",")))
# print(solution(a, b))