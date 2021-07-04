def solution(d, budget):
    answer = 0
    d.sort()
    for _, i in enumerate(d):
        if i <= budget:
            answer += 1
            budget -= i
        
    return answer
