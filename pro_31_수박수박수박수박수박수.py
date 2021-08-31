def solution(n):
    answer = ''
    quotient = n // 2
    remainder = n % 2
    answer += "수박" * quotient
    answer += "수" * remainder
    return answer

# n = int(input())
# print(solution(n))