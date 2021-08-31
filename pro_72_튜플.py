def solution(s):
    answer = []
    candidates = []
    tuple_set = s[1:len(s)-1].split('},{')
    for s in tuple_set:
        candidates.append(set(map(int, s.rstrip('}').lstrip('{').split(','))))
    candidates = sorted(candidates, key=len)
    if len(candidates) > 1:
        answer.append(list(candidates[0])[0])
        for i in range(1, len(candidates)):
            difference = candidates[i] - candidates[i-1]
            answer.append(list(difference)[0])
    else:
        answer = list(candidates[0])
    return answer

# print(solution(input()))