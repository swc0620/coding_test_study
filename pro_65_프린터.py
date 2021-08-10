def solution(priorities, location):
    count = 0
    while True:
        print(priorities, location)
        temp = priorities.pop(0)
        if not priorities:
            return count + 1
        if temp < max(priorities):
            priorities.append(temp)
            if location == 0:
                location = len(priorities) - 1
            else:
                location -= 1
        else:
            if location == 0:
                return count + 1
            else:
                location -= 1
                count += 1
    return count

# priorities = list(map(int, input().split()))
# location = int(input())
# print(solution(priorities, location))