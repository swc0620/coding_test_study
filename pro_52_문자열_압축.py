def solution(s):
    answer = 1001
    for i in range(1, len(s)//2+1):
        candidate = ""
        count = 1
        for j in range(0, len(s), i):
            if s[j:j+i] == s[j+i:j+2*i]:
                count += 1
            else:
                if count == 1:
                    candidate += s[j:j+i]
                else:
                    candidate += str(count)
                    candidate += s[j:j+i]
                count = 1
        if len(candidate) < answer:
            answer = len(candidate)
    if answer == 1001:
        answer = 1
    return answer
    
# print(solution(input()))