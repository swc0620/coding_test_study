def solution(a, b):
    answer = 4
    days = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT']
    months = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    for month in range(a):
        answer += months[month]
    answer += b
    answer %= 7
    return days[answer]

# a = int(input())
# b = int(input())
# print(solution(a,b))