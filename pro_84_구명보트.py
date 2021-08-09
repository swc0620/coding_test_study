def solution(people, limit):
    answer = 0
    people = sorted(people, reverse=True)
    heavy = 0
    light = len(people) - 1
    while heavy <= light:
        if people[heavy] + people[light] <= limit:
            light -= 1
        answer += 1
        heavy += 1
    return answer

# people = list(map(int, input().split()))
# limit = int(input())
# print(solution(people, limit))