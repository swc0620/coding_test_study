def solution(n):
    answer = 0
    # 에라토스테네스의 체
    array = [True] * (n + 1)
    m = int(n ** 0.5)
    for i in range(2, m + 1):
        if array[i] == True:
            for j in range(i + i, n + 1, i):
                array[j] = False
                
    for i in range(2, n + 1):
        if array[i] == True:
            answer += 1
    return answer
