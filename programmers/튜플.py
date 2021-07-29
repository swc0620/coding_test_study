def solution(s):
    answer = []
    s = s[2:-2]
    s = s.split('},{')
    s = sorted(s, key=lambda x: len(x))
    
    answer.append(s[0])
    
    for i in range(1, len(s)):
        s[i] = s[i].split(',')
        for j in s[i]:
            if j not in answer:
                answer.append(j)
    answer = list(map(int, answer))
    return answer
