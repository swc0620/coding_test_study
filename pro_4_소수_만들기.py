from itertools import combinations

def solution(nums):
    answer = 0

    num_combs = list(combinations(nums, 3))

    for index in range(len(num_combs)):
        candidate = sum(num_combs[index])
        prime = 1
        for i in range(2, candidate // 2):
            if candidate % i == 0:
                prime = 0
                break
        if prime:
            answer += 1
    return answer

# nums = list(map(int, input().split(",")))
# print(solution(nums))