def solution(n):
    stack = []
    while n > 0:
        stack.append(n % 3)
        n //= 3

    answer = 0
    for i in range(len(stack)-1, -1, -1):
        answer += stack[i] * 3 ** (len(stack) - 1 - i)
    
    return answer

# n = int(input())
# print(solution(n))