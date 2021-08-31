def solution(n, lost, reserve):
    new_lost = list(set(lost) - set(reserve))
    new_reserve = list(set(reserve) - set(lost))

    for student in new_lost:
        if student + 1 in new_reserve:
            new_reserve.remove(student+1)
        elif student - 1 in new_reserve:
            new_reserve.remove(student-1)
        else:
            n -= 1
    return n

# n = int(input())
# lost = list(map(int, input().split(",")))
# reserve = list(map(int, input().split(",")))
# print(solution(n, lost, reserve))

