def solution(numbers):
    answer = ''
    num = list(map(str, numbers))
    num.sort(key=lambda x: x*3, reverse=True)
    return str(int("".join(num)))

# numbers = list(map(int, input().split()))
# print(solution(numbers))