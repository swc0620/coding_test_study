def solution(n):
    answer = 0
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            if i != n // i:
                answer += i
                answer += n // i
            else:
                answer += i
    return answer

# print(solution(int(input())))