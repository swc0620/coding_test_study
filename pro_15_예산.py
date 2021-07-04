def solution(d, budget):
    d = sorted(d)
    answer = 0
    i = 0
    while i < len(d):
        answer += d[i]
        if answer > budget:
            return i
        i += 1
    return i

# d = list(map(int, input().split(",")))
# budget = int(input())
# print(solution(d, budget))