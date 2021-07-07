from itertools import combinations

def solution(numbers):
    num_comb = combinations(numbers, 2)
    answer = [sum(i) for i in num_comb]
    answer = sorted(list(set(answer)))
    return answer

# numbers = list(map(int, input().split(",")))
# print(solution(numbers))