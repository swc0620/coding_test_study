def repeat(s, zeros):
    s.sort()
    for idx, num in enumerate(s):
        if num == '1':
            break
    s = s[idx:]
    return s, idx

def solution(s):
    answer = []
    zeros = 0
    
    i = 0
    zero = 0
    while True:
        if s == '1':
            answer.append(i)
            answer.append(zero)
            break
        s = list(s)
        i += 1
        s, zeros = repeat(s, zeros)
        zero += zeros
        s = bin(len(s))[2:]
    
    return answer

# print(solution(input()))