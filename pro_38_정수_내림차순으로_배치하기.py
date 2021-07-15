def solution(n):
    answer = sorted(str(n), reverse=True)
    answer = int(''.join(answer))
    return answer

# print(solution(int(input())))