from collections import deque

def solution(numbers, target):
    queue = []
    length = len(numbers)
    answer = 0
    queue = deque()
    queue.append([numbers[0], 0])
    queue.append([-1*numbers[0], 0])
    while queue:
        n, level = queue.popleft()
        level += 1
        if level < length:
            queue.append([n + numbers[level], level])
            queue.append([n - numbers[level], level])
        else:
            if n == target:
                answer += 1
    return answer


# numbers = list(map(int, input().split(",")))
# target = int(input())
# print(solution(numbers, target))