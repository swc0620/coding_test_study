def solution(left, right):
    answer = 0
    for i in range(left, right + 1):
        count = 0
        for j in range(1, int(i ** 0.5) + 1):
            if i % j == 0:
                count += 2
                
            if i ** 0.5 == i // j: # 제곱근이 약수에 포함된 경우 -1 ex) 1, 2, 4
                count -= 1
                
        if count % 2 == 0:
            answer += i
        else:
            answer -= i
    return answer
