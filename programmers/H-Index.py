def solution(citations):
    answer = 0
    sor_cite = sorted(citations, reverse=True)
    for ele in sor_cite:
        answer += 1
        if ele == answer:
            return answer
        elif ele < answer:
            return answer - 1
    return answer
